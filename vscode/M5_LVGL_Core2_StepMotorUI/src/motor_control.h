#include <Arduino.h>
#include <M5Unified.h>
#include <FastAccelStepper.h>
#include <Module_Stepmotor.h>
#include "ui/vars.h"
#include "main.h"

#ifndef MY_MOTOR_CONTROL_H
#define MY_MOTOR_CONTROL_H

#define X_DIR_PIN G14
#define X_STEP_PIN G13
#define Y_DIR_PIN G19
#define Y_STEP_PIN G27
#define Z_DIR_PIN G0
#define Z_STEP_PIN G2

#define RS485_TX G25
#define RS485_RX G34

#define MODBUS_ADDRESS 3
#define RS485_SERIAL Serial2
#define RS485_BAUDRATE 115200

extern FastAccelStepperEngine motorController;
extern FastAccelStepper *motorX;
extern FastAccelStepper *motorY;
extern FastAccelStepper *motorZ;

extern Module_Stepmotor motorDriver;

struct MotorsParam
{
    uint32_t id; //= 0x4D50524D: 'MPRM'
    uint8_t version;

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

MotorsParam defaultMotorsParam();

extern MotorsParam motorParam;

extern bool motorEnabled;

extern bool run_0;
extern bool run_1;
extern bool run_2;

extern int EEPROM_ADDRESS_MPRM ;
extern int EEPROM_SIZE_MPRM;

void updateUI(const MotorsParam &params);
void setupMotor(FastAccelStepper **motor, int stepPin, int dirPin, int acceleration, int ppr);

void driverPowerON();
void driverPowerOFF();
void motorRun(int motorIndex);
void motorStop(int index);
bool updateMotorParam(int index, int ppr, int acc_rpm, bool rev);

void RS485_Init();
void RS485_Write(const uint8_t *data, size_t length);
size_t RS485_Read(uint8_t *buffer, size_t bufferSize, uint32_t timeout);

void handleModbusRequest();
void processModbusFrame(const uint8_t *frame, size_t length);
uint16_t Modbus_CRC16(const uint8_t *data, size_t length);

void saveEEPROM(const MotorsParam &MPRM);
MotorsParam loadMPRMfromEEPROM();

#endif