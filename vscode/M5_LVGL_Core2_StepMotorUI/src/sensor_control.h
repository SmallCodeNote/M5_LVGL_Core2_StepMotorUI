#include <Arduino.h>
#include <M5Unified.h>
#include <VL53L1X.h>
#include "ui/vars.h"
#include "ui/screens.h"

#ifndef MY_SENSOR_CONTROL_H
#define MY_SENSOR_CONTROL_H

extern lv_chart_series_t * chart_sensor_view_ser1;

extern VL53L1X tofSensor;
extern int tofSensorInterval;
void setupSensorROI(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);

void setupSensor();

#endif