#include <Arduino.h>
#include <M5Unified.h>
#include <Module_Stepmotor.h>
#include <FastAccelStepper.h>

#include "ui/ui.h"
#include "ui/eez-flow.h"
#include "my_common_code.h"
#include "motor_control.h"

#include "my_debug.h"
#include "sensor_control.h"
#include "ui/screens.h"

void modbusTask(void* pvParameters) {
  while (true) {
    handleModbusRequest();  // RS485_Read()をここで実行
    vTaskDelay(10 / portTICK_PERIOD_MS);  // 軽い待機
  }
}

void setup()
{
  auto cfg = M5.config();
  cfg.internal_imu = false;
  M5.begin(cfg);

  String LVGL_Arduino = "LVGL information : ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(115200);
  Serial.println(LVGL_Arduino);

  my_device_initialize(M5.Display);
  lv_init();
  ui_init();

  motorParam = loadEEPROM();
  motorController.init();

  setupMotor(&motorX, X_STEP_PIN, X_DIR_PIN, motorParam.acc_rpm_0, motorParam.ppr_0);
  setupMotor(&motorY, Y_STEP_PIN, Y_DIR_PIN, motorParam.acc_rpm_1, motorParam.ppr_1);
  setupMotor(&motorZ, Z_STEP_PIN, Z_DIR_PIN, motorParam.acc_rpm_2, motorParam.ppr_2);

  // Driver init. Core2 internal i2c port
  motorDriver.init(Wire1);

  // Reset motor drivers v1.1
  motorDriver.resetMotor(0, 0);
  motorDriver.resetMotor(1, 0);
  motorDriver.resetMotor(2, 0);

  // Disable power supply to motors
  motorDriver.enableMotor(0);
  motorEnabled = false;

  setupSensor();

  lv_chart_set_range(objects.chart_sensor_view, LV_CHART_AXIS_PRIMARY_Y, 0, 150);
  lv_chart_set_range(objects.chart_sensor_view, LV_CHART_AXIS_SECONDARY_Y, 0, 300);
  chart_sensor_view_ser1 = lv_chart_add_series(objects.chart_sensor_view, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
  for (size_t i = 0; i < 10; i++)
  {
    chart_sensor_view_ser1->y_points[i] = 0;
  }
  
  RS485_Init();
  xTaskCreate(modbusTask, "ModbusTask", 4096, NULL, 1, NULL);

  updateUI(motorParam);
  saveEEPROM(motorParam);
}

int waitCountUnit = 10;
int waitCountSum = 0;

int sensorCounter = 0;

void update_chart_sensor_view_ser1()
{
  for (size_t i = 0; i < 9; i++)
  {
    chart_sensor_view_ser1->y_points[i] = chart_sensor_view_ser1->y_points[i + 1];
  }
}

void loop()
{
  M5.update();
  lv_task_handler();
  ui_tick();
  vTaskDelay(waitCountUnit);
  waitCountSum += waitCountUnit;

  if (tofSensorInterval > 0)
  {
    sensorCounter += waitCountUnit;
    if (sensorCounter >= tofSensorInterval)
    {
      int sensorValue = (int)tofSensor.read();
      set_var_sensor_value(sensorValue);

      update_chart_sensor_view_ser1();

      chart_sensor_view_ser1->y_points[9] = sensorValue;
      lv_chart_refresh(objects.chart_sensor_view);

      sensorCounter = 0;
    }
  }

  if (waitCountSum > 1000)
  {
    int pvx = int(motorX->getCurrentSpeedInMilliHz(true));
    int pvy = int(motorY->getCurrentSpeedInMilliHz(true));
    int pvz = int(motorZ->getCurrentSpeedInMilliHz(true));

    pvx = (pvx * 60) / motorParam.ppr_0 / 1000;
    pvy = (pvy * 60) / motorParam.ppr_1 / 1000;
    pvz = (pvz * 60) / motorParam.ppr_2 / 1000;

    set_var_motor_pv_0(pvx);
    set_var_motor_pv_1(pvy);
    set_var_motor_pv_2(pvz);

    if (!pvx && !run_0)
    {
      set_var_motor_run_0(false);
    };
    if (!pvy && !run_1)
    {
      set_var_motor_run_1(false);
    };
    if (!pvz && !run_2)
    {
      set_var_motor_run_2(false);
    };

    if (motorEnabled && !run_0 && !run_1 && !run_2 && !pvx && !pvy && !pvz)
    {
      motorDriver.enableMotor(0);
      motorEnabled = false;
    }

    waitCountSum = 0;
  }
}