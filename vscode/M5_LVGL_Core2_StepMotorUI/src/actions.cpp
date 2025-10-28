#include <Arduino.h>
#include <M5Unified.h>

#include "ui/actions.h"
#include "ui/vars.h"

#include "motor_control.h"
#include "sensor_control.h"

#include "my_debug.h"

extern "C" void action_motor_sv_update_0(lv_event_t *e)
{
    motorParam.sv_0 = get_var_motor_sv_0();
    run_0 = get_var_motor_run_0();
    if (run_0)
    {
        motorRun(0);
    }
}

extern "C" void action_motor_sv_update_1(lv_event_t *e)
{
    motorParam.sv_1 = get_var_motor_sv_1();
    run_1 = get_var_motor_run_1();
    if (run_1)
    {
        motorRun(1);
    }
}

extern "C" void action_motor_sv_update_2(lv_event_t *e)
{
    motorParam.sv_2 = get_var_motor_sv_2();
    run_2 = get_var_motor_run_2();
    if (run_2)
    {
        motorRun(2);
    }
}

extern "C" void action_motor_run_update_0(lv_event_t *e)
{
    run_0 = get_var_motor_run_0();
    if (run_0)
    {
        motorRun(0);
    }
    else
    {
        motorStop(0);
    }
}

extern "C" void action_motor_run_update_1(lv_event_t *e)
{
    run_1 = get_var_motor_run_1();
    if (run_1)
    {
        motorRun(1);
    }
    else
    {
        motorStop(1);
    }
}

extern "C" void action_motor_run_update_2(lv_event_t *e)
{
    run_2 = get_var_motor_run_2();
    if (run_2)
    {
        motorRun(2);
    }
    else
    {
        motorStop(2);
    }
}

extern "C" void action_motor_param_update_0(lv_event_t *e)
{
    DEBUG_PRINT_LOCATION();
    bool changed = updateMotorParam(0, get_var_motor_ppr_0(), get_var_motor_acceleration_0(), get_var_motor_direction_rev_0());
    motorX->setAcceleration(motorParam.acc_rpm_0 * motorParam.ppr_0 / 60);

    if (changed)
    {
        saveEEPROM(motorParam);
        Serial.println("[EEPROM] motorParam saved.");
    }
    else
    {
        Serial.println("[EEPROM] No changes detected. Save skipped.");
    }
}

extern "C" void action_motor_param_update_1(lv_event_t *e)
{
    DEBUG_PRINT_LOCATION();
    bool changed = updateMotorParam(1, get_var_motor_ppr_1(), get_var_motor_acceleration_1(), get_var_motor_direction_rev_1());
    motorX->setAcceleration(motorParam.acc_rpm_1 * motorParam.ppr_1 / 60);

    if (changed)
    {
        saveEEPROM(motorParam);
        Serial.println("[EEPROM] motorParam saved.");
    }
    else
    {
        Serial.println("[EEPROM] No changes detected. Save skipped.");
    }
}

extern "C" void action_motor_param_update_2(lv_event_t *e)
{
    bool changed = updateMotorParam(2, get_var_motor_ppr_2(), get_var_motor_acceleration_2(), get_var_motor_direction_rev_2());
    motorX->setAcceleration(motorParam.acc_rpm_2 * motorParam.ppr_2 / 60);

    if (changed)
    {
        saveEEPROM(motorParam);
        Serial.println("[EEPROM] motorParam saved.");
    }
    else
    {
        Serial.println("[EEPROM] No changes detected. Save skipped.");
    }
}

extern "C" void action_sensor_param_update(lv_event_t *e)
{
    int topLeftX = get_var_sensor_top_left_x();
    int topLeftY = get_var_sensor_top_left_y();
    int bottomRightX = get_var_sensor_bottom_right_x();
    int bottomRightY = get_var_sensor_bottom_right_y();
    int interval = get_var_sensor_interval();

    sensorParam.topLeftX = topLeftX;
    sensorParam.topLeftX = topLeftX;
    sensorParam.topLeftY = topLeftY;
    sensorParam.bottomRightX = bottomRightX;
    sensorParam.bottomRightY = bottomRightY;
    sensorParam.interval = interval;

    Serial.println("[action_sensor_param_update]:");
    Serial.printf("  topLeftX = %d\n", sensorParam.topLeftX);
    Serial.printf("  topLeftY = %d\n", sensorParam.topLeftY);
    Serial.printf("  bottomRightX = %d\n", sensorParam.bottomRightX);
    Serial.printf("  bottomRightY = %d\n", sensorParam.bottomRightY);
    Serial.printf("  interval = %d\n", sensorParam.interval);

    setupSensorROI(topLeftX, topLeftY, bottomRightX, bottomRightY);
}
