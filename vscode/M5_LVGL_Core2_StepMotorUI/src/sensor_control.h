#include <Arduino.h>
#include <M5Unified.h>
#include <VL53L1X.h>
#include "ui/vars.h"
#include "ui/screens.h"

#ifndef MY_SENSOR_CONTROL_H
#define MY_SENSOR_CONTROL_H

extern lv_chart_series_t *chart_sensor_view_ser1;

extern VL53L1X tofSensor;

void setupSensorROI(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);

void setupSensor();

struct SensorParam
{
    uint32_t id; // = 0x534E5352 : 'SNSR'
    uint8_t version;

    int8_t topLeftX;
    int8_t topLeftY;
    int8_t bottomRightX;
    int8_t bottomRightY;
    int32_t interval;
};

extern SensorParam sensorParam;
extern int EEPROM_ADDRESS_SPRM ;
extern int EEPROM_SIZE_SPRM;

void saveEEPROM(const SensorParam &SPRM);
SensorParam loadSPRMfromEEPROM();

void updateUI(const SensorParam &params);

#endif