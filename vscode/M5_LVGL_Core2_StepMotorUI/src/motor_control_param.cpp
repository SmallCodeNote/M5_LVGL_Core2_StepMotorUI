#include <EEPROM.h>
#include <FastAccelStepper.h>
#include <Module_Stepmotor.h>
#include "motor_control_param.h"
#include "ui/vars.h"

FastAccelStepperEngine motorController = FastAccelStepperEngine();
FastAccelStepper *motorX = nullptr;
FastAccelStepper *motorY = nullptr;
FastAccelStepper *motorZ = nullptr;

Module_Stepmotor motorDriver = Module_Stepmotor();

MotorsParam motorParam;

bool motorEnabled = false; // flag to check if the motor is enabled

const int EEPROM_ADDRESS = 0;
const int EEPROM_SIZE = sizeof(MotorsParam);

bool inUpdateCall = false;

bool run_0 = false;
bool run_1 = false;
bool run_2 = false;

void saveEEPROM(const MotorsParam &params)
{
    if (inUpdateCall)
        return;

    EEPROM.begin(EEPROM_SIZE);
    EEPROM.put(EEPROM_ADDRESS, params);
    EEPROM.commit(); // for ESP32
    EEPROM.end();

    Serial.println("[EEPROM] Saved motor parameters:");
    Serial.printf("  motor_ppr_0 = %d\n", params.ppr_0);
    Serial.printf("  motor_ppr_1 = %d\n", params.ppr_1);
    Serial.printf("  motor_ppr_2 = %d\n", params.ppr_2);

    Serial.printf("  motor_acceleration_0 = %d\n", params.acc_rpm_0);
    Serial.printf("  motor_acceleration_1 = %d\n", params.acc_rpm_1);
    Serial.printf("  motor_acceleration_2 = %d\n", params.acc_rpm_2);

    Serial.printf("  motor_sv_0 = %d\n", params.sv_0);
    Serial.printf("  motor_sv_1 = %d\n", params.sv_1);
    Serial.printf("  motor_sv_2 = %d\n", params.sv_2);

    Serial.printf("  motor_direction_rev_0 = %s\n", params.rev_0 ? "true" : "false");
    Serial.printf("  motor_direction_rev_1 = %s\n", params.rev_1 ? "true" : "false");
    Serial.printf("  motor_direction_rev_2 = %s\n", params.rev_2 ? "true" : "false");
}

MotorsParam loadEEPROM()
{
    MotorsParam params;
    EEPROM.begin(EEPROM_SIZE);
    EEPROM.get(EEPROM_ADDRESS, params);
    EEPROM.end();

    Serial.println("[EEPROM] Loaded motor parameters:");
    Serial.printf("  motor_ppr_0 = %d\n", params.ppr_0);
    Serial.printf("  motor_ppr_1 = %d\n", params.ppr_1);
    Serial.printf("  motor_ppr_2 = %d\n", params.ppr_2);

    Serial.printf("  motor_acceleration_0 = %d\n", params.acc_rpm_0);
    Serial.printf("  motor_acceleration_1 = %d\n", params.acc_rpm_1);
    Serial.printf("  motor_acceleration_2 = %d\n", params.acc_rpm_2);

    Serial.printf("  motor_sv_0 = %d\n", params.sv_0);
    Serial.printf("  motor_sv_1 = %d\n", params.sv_1);
    Serial.printf("  motor_sv_2 = %d\n", params.sv_2);

    Serial.printf("  motor_direction_rev_0 = %s\n", params.rev_0 ? "true" : "false");
    Serial.printf("  motor_direction_rev_1 = %s\n", params.rev_1 ? "true" : "false");
    Serial.printf("  motor_direction_rev_2 = %s\n", params.rev_2 ? "true" : "false");

    return params;
}

void updateUI(const MotorsParam &params)
{
    inUpdateCall = true;
    set_var_motor_acceleration_0(params.acc_rpm_0);
    set_var_motor_acceleration_1(params.acc_rpm_1);
    set_var_motor_acceleration_2(params.acc_rpm_2);

    set_var_motor_ppr_0(params.ppr_0);
    set_var_motor_ppr_1(params.ppr_1);
    set_var_motor_ppr_2(params.ppr_2);

    set_var_motor_direction_rev_0(params.rev_0);
    set_var_motor_direction_rev_1(params.rev_1);
    set_var_motor_direction_rev_2(params.rev_2);

    set_var_motor_sv_0(params.sv_0);
    set_var_motor_sv_1(params.sv_1);
    set_var_motor_sv_2(params.sv_2);

    // Serial出力
    Serial.println("[UI] Updated motor parameters:");
    Serial.printf("  motor_acceleration_0 = %d\n", params.acc_rpm_0);
    Serial.printf("  motor_acceleration_1 = %d\n", params.acc_rpm_1);
    Serial.printf("  motor_acceleration_2 = %d\n", params.acc_rpm_2);

    Serial.printf("  motor_ppr_0 = %d\n", params.ppr_0);
    Serial.printf("  motor_ppr_1 = %d\n", params.ppr_1);
    Serial.printf("  motor_ppr_2 = %d\n", params.ppr_2);

    Serial.printf("  motor_direction_rev_0 = %s\n", params.rev_0 ? "true" : "false");
    Serial.printf("  motor_direction_rev_1 = %s\n", params.rev_1 ? "true" : "false");
    Serial.printf("  motor_direction_rev_2 = %s\n", params.rev_2 ? "true" : "false");
    inUpdateCall = false;
}

void setupMotor(FastAccelStepper **motor, int stepPin, int dirPin, int acceleration, int ppr)
{
    *motor = motorController.stepperConnectToPin(stepPin);
    (*motor)->setDirectionPin(dirPin);
    (*motor)->setAutoEnable(true);
    (*motor)->setSpeedInHz(0);
    (*motor)->setAcceleration(acceleration * ppr / 60);
}

bool updateMotorParam(int index, int ppr, int acc_rpm, bool rev)
{
    bool changed = false;

    if (index == 0)
    {
        changed = motorParam.ppr_0 != ppr || motorParam.acc_rpm_0 != acc_rpm || motorParam.rev_0 != rev;
        motorParam.ppr_0 = ppr;
        motorParam.acc_rpm_0 = acc_rpm;
        motorParam.rev_0 = rev;
    }
    else if (index == 1)
    {
        changed = motorParam.ppr_1 != ppr || motorParam.acc_rpm_1 != acc_rpm || motorParam.rev_1 != rev;
        motorParam.ppr_1 = ppr;
        motorParam.acc_rpm_1 = acc_rpm;
        motorParam.rev_1 = rev;
    }
    else if (index == 2)
    {
        changed = motorParam.ppr_2 != ppr || motorParam.acc_rpm_2 != acc_rpm || motorParam.rev_2 != rev;
        motorParam.ppr_2 = ppr;
        motorParam.acc_rpm_2 = acc_rpm;
        motorParam.rev_2 = rev;
    }

    return changed;
}

void driverPowerON()
{
    if (!motorEnabled)
    {
        motorEnabled = true;
        motorDriver.enableMotor(1);
    }
}

void driverRunCheckAndPowerOFF()
{
    if (motorEnabled && !run_0 && !run_1 && !run_2)
    {
        motorEnabled = false;
        motorDriver.enableMotor(0);
    }
}

void motorRun(int index)
{
    driverPowerON();

    int pps = 0;
    bool rev = false;
    FastAccelStepper *motor = nullptr;

    switch (index)
    {
    case 0:
        pps = (motorParam.sv_0 * motorParam.ppr_0) / 60;
        rev = motorParam.rev_0;
        motor = motorX;
        break;
    case 1:
        pps = (motorParam.sv_1 * motorParam.ppr_1) / 60;
        rev = motorParam.rev_1;
        motor = motorY;
        break;
    case 2:
        pps = (motorParam.sv_2 * motorParam.ppr_2) / 60;
        rev = motorParam.rev_2;
        motor = motorZ;
        break;

    default:
        break;
    }

    motor->setSpeedInHz(pps);

    if (rev)
    {
        motor->runBackward();
    }
    else
    {
        motor->runForward();
    }
}

void motorStop(int index)
{
    FastAccelStepper *motor = nullptr;

    switch (index)
    {
    case 0:
        motor = motorX;
        break;
    case 1:
        motor = motorY;
        break;
    case 2:
        motor = motorZ;
        break;

    default:
        break;
    }
    motor->stopMove();
}
