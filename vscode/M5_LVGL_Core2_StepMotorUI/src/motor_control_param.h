#include <Arduino.h>
#include <M5Unified.h>
#include <FastAccelStepper.h>
#include <Module_Stepmotor.h>
#include "ui/vars.h"

#ifndef MY_MOTOR_CONTROL_PARAM_H
#define MY_MOTOR_CONTROL_PARAM_H

#define X_DIR_PIN G14
#define X_STEP_PIN G13
#define Y_DIR_PIN G19
#define Y_STEP_PIN G27
#define Z_DIR_PIN G0
#define Z_STEP_PIN G2

extern FastAccelStepperEngine motorController;
extern FastAccelStepper *motorX;
extern FastAccelStepper *motorY;
extern FastAccelStepper *motorZ;

extern Module_Stepmotor motorDriver;

struct MotorsParam
{
    int32_t ppr_0;
    int32_t ppr_1;
    int32_t ppr_2;

    int32_t acc_rpm_0;
    int32_t acc_rpm_1;
    int32_t acc_rpm_2;

    int32_t sv_0;
    int32_t sv_1;
    int32_t sv_2;

    bool rev_0;
    bool rev_1;
    bool rev_2;
};

extern MotorsParam motorParam;

extern bool motorEnabled;

extern bool run_0;
extern bool run_1;
extern bool run_2;

void saveEEPROM(const MotorsParam &params);
MotorsParam loadEEPROM();
void updateUI(const MotorsParam &params);
void setupMotor(FastAccelStepper** motor, int stepPin, int dirPin, int acceleration, int ppr);

void driverPowerON();
void driverPowerOFF();
void motorRun(int motorIndex);
void motorStop(int index);
bool updateMotorParam(int index, int ppr, int acc_rpm, bool rev);

#endif