#include <Arduino.h>
#include <M5Unified.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <EEPROM.h>

#include "sensor_control.h"
#include "main.h"

VL53L1X tofSensor;
SensorParam sensorParam;

lv_chart_series_t * chart_sensor_view_ser1;


const uint8_t spadMap[16][16] = {
  { 128,136,144,152,160,168,176,184,192,200,208,216,224,232,240,248 },
  { 129,137,145,153,161,169,177,185,193,201,209,217,225,233,241,249 },
  { 130,138,146,154,162,170,178,186,194,202,210,218,226,234,242,250 },
  { 131,139,147,155,163,171,179,187,195,203,211,219,227,235,243,251 },
  { 132,140,148,156,164,172,180,188,196,204,212,220,228,236,244,252 },
  { 133,141,149,157,165,173,181,189,197,205,213,221,229,237,245,253 },
  { 134,142,150,158,166,174,182,190,198,206,214,222,230,238,246,254 },
  { 135,143,151,159,167,175,183,191,199,207,215,223,231,239,247,255 },
  { 127,119,111,103, 95, 87, 79, 71, 63, 55, 47, 39, 31, 23, 15,  7 },
  { 126,118,110,102, 94, 86, 78, 70, 62, 54, 46, 38, 30, 22, 14,  6 },
  { 125,117,109,101, 93, 85, 77, 69, 61, 53, 45, 37, 29, 21, 13,  5 },
  { 124,116,108,100, 92, 84, 76, 68, 60, 52, 44, 36, 28, 20, 12,  4 },
  { 123,115,107, 99, 91, 83, 75, 67, 59, 51, 43, 35, 27, 19, 11,  3 },
  { 122,114,106, 98, 90, 82, 74, 66, 58, 50, 42, 34, 26, 18, 10,  2 },
  { 121,113,105, 97, 89, 81, 73, 65, 57, 49, 41, 33, 25, 17,  9,  1 },
  { 120,112,104, 96, 88, 80, 72, 64, 56, 48, 40, 32, 24, 16,  8,  0 }
};

int EEPROM_ADDRESS_SPRM = 0;
int EEPROM_SIZE_SPRM = sizeof(SensorParam);
uint32_t EEPROM_ID_SPRM = 0x534E5352; // 'SNSR'
uint8_t EEPROM_VERSION_SPRM = 1; 

SensorParam defaultSensorParam() {
  SensorParam s;
  s.id = EEPROM_ID_SPRM;
  s.version = EEPROM_VERSION_SPRM;
  s.topLeftX = 0;
  s.topLeftY = 0;
  s.bottomRightX = 14;
  s.bottomRightY = 14;
  s.interval = 500;
  return s;
}

void saveEEPROM(const SensorParam &params)
{
    if (inUpdateCall)
        return;

    EEPROM.begin(EEPROM_SIZE_SPRM);
    EEPROM.put(EEPROM_ADDRESS_SPRM, params);
    EEPROM.commit(); // for ESP32
    EEPROM.end();

    Serial.println("[EEPROM] Saved sensor parameters:");
    Serial.printf("  topLeftX = %d\n", params.topLeftX);
    Serial.printf("  topLeftY = %d\n", params.topLeftY);
    Serial.printf("  bottomRightX = %d\n", params.bottomRightX);
    Serial.printf("  bottomRightY = %d\n", params.bottomRightY);
    Serial.printf("  interval = %d\n", params.interval);
}

SensorParam loadSPRMfromEEPROM()
{
    SensorParam params;
    EEPROM.begin(EEPROM_SIZE_SPRM);
    EEPROM.get(EEPROM_ADDRESS_SPRM, params);
    EEPROM.end();

    if (params.id == EEPROM_ID_SPRM && params.version == EEPROM_VERSION_SPRM)
    {
        Serial.println("[EEPROM] Loaded sensor parameters:");
        Serial.printf("  topLeftX = %d\n", params.topLeftX);
        Serial.printf("  topLeftY = %d\n", params.topLeftY);
        Serial.printf("  bottomRightX = %d\n", params.bottomRightX);
        Serial.printf("  bottomRightY = %d\n", params.bottomRightY);
        Serial.printf("  interval = %d\n", params.interval);
    }
    else
    {
        Serial.println("[EEPROM] Loaded sensor parameters error:");
        return defaultSensorParam();
    }
    return params;
}

void setupSensor()
{
    M5.Ex_I2C.begin();
    tofSensor.setBus(&Wire);
    tofSensor.setTimeout(500);
    if(!tofSensor.init())
    {
        Serial.println("Failed to detect and initialize sensor!");
        return;
    }

    tofSensor.setDistanceMode(VL53L1X::Short);
    tofSensor.setMeasurementTimingBudget(50000); // 測定周期（μs）
    tofSensor.startContinuous(50);
}

void setupSensorROI(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
  topLeftX = constrain(topLeftX, 0, 14);
  topLeftY = constrain(topLeftY, 0, 14);
  bottomRightX = constrain(bottomRightX, topLeftX + 1, 15);
  bottomRightY = constrain(bottomRightY, topLeftY + 1, 15);

  int roiWidth = bottomRightX - topLeftX + 1;
  int roiHeight = bottomRightY - topLeftY + 1;

  if (roiWidth % 2 != 0) roiWidth--;
  if (roiHeight % 2 != 0) roiHeight--;

  int centerX = topLeftX + roiWidth / 2;
  int centerY = topLeftY + roiHeight / 2;

  centerX = constrain(centerX, 0, 15);
  centerY = constrain(centerY, 0, 15);

  uint8_t spadNumber = spadMap[centerY][centerX];

  tofSensor.setROISize(roiWidth, roiHeight);
  tofSensor.setROICenter(spadNumber);
}


void updateUI(const SensorParam &params)
{
    inUpdateCall = true;

    set_var_sensor_top_left_x(params.topLeftX);
    set_var_sensor_top_left_y(params.topLeftY);
    set_var_sensor_bottom_right_x(params.bottomRightX);
    set_var_sensor_bottom_right_y(params.bottomRightY);
    set_var_sensor_interval(params.interval);


    Serial.println("[UI] Updated sensor parameters:");
    Serial.printf("  topLeftX = %d\n", params.topLeftX);
    Serial.printf("  topLeftY = %d\n", params.topLeftY);
    Serial.printf("  bottomRightX = %d\n", params.bottomRightX);
    Serial.printf("  bottomRightY = %d\n", params.bottomRightY);
    Serial.printf("  interval = %d\n", params.interval);

    inUpdateCall = false;
}

