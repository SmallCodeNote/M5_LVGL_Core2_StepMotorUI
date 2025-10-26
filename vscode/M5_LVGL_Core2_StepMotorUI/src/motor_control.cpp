#include <EEPROM.h>
#include <FastAccelStepper.h>
#include <Module_Stepmotor.h>
#include "motor_control.h"
#include "ui/vars.h"

FastAccelStepperEngine motorController = FastAccelStepperEngine();
FastAccelStepper *motorX = nullptr;
FastAccelStepper *motorY = nullptr;
FastAccelStepper *motorZ = nullptr;

Module_Stepmotor motorDriver = Module_Stepmotor();
MotorsParam motorParam;

void RS485_Init()
{
    RS485_SERIAL.begin(RS485_BAUDRATE, SERIAL_8N1, RS485_RX, RS485_TX);
    delay(100);
}

void RS485_Write(const uint8_t *data, size_t length)
{
    RS485_SERIAL.write(data, length);
    RS485_SERIAL.flush();
}

size_t RS485_Read(uint8_t *buffer, size_t bufferSize, uint32_t timeout = 100)
{
    size_t bytesRead = 0;
    uint32_t startTime = millis();

    while ((millis() - startTime) < timeout && bytesRead < bufferSize)
    {
        if (RS485_SERIAL.available())
        {
            buffer[bytesRead++] = RS485_SERIAL.read();
        }
    }

    return bytesRead;
}

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

    set_var_motor_sv_0(params.sv_0);
    set_var_motor_sv_1(params.sv_1);
    set_var_motor_sv_2(params.sv_2);

    set_var_motor_direction_rev_0(params.rev_0);
    set_var_motor_direction_rev_1(params.rev_1);
    set_var_motor_direction_rev_2(params.rev_2);

    // Serial出力
    Serial.println("[UI] Updated motor parameters:");
    Serial.printf("  motor_acceleration_0 = %d\n", params.acc_rpm_0);
    Serial.printf("  motor_acceleration_1 = %d\n", params.acc_rpm_1);
    Serial.printf("  motor_acceleration_2 = %d\n", params.acc_rpm_2);

    Serial.printf("  motor_ppr_0 = %d\n", params.ppr_0);
    Serial.printf("  motor_ppr_1 = %d\n", params.ppr_1);
    Serial.printf("  motor_ppr_2 = %d\n", params.ppr_2);

    Serial.printf("  motor_sv_0 = %d\n", params.sv_0);
    Serial.printf("  motor_sv_1 = %d\n", params.sv_1);
    Serial.printf("  motor_sv_2 = %d\n", params.sv_2);

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

    int acc = 200;
    int pps = 0;
    bool rev = false;
    FastAccelStepper *motor = nullptr;

    switch (index)
    {
    case 0:
        pps = (motorParam.sv_0 * motorParam.ppr_0) / 60;
        rev = motorParam.rev_0;
        acc = motorParam.acc_rpm_0 * motorParam.ppr_0 / 60;
        motor = motorX;
        break;
    case 1:
        pps = (motorParam.sv_1 * motorParam.ppr_1) / 60;
        rev = motorParam.rev_1;
        acc = motorParam.acc_rpm_1 * motorParam.ppr_1 / 60;
        motor = motorY;
        break;
    case 2:
        pps = (motorParam.sv_2 * motorParam.ppr_2) / 60;
        rev = motorParam.rev_2;
        acc = motorParam.acc_rpm_2 * motorParam.ppr_2 / 60;
        motor = motorZ;
        break;

    default:
        break;
    }

    motor->setSpeedInHz(pps);
    motor->setAcceleration(acc);

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

uint16_t Modbus_CRC16(const uint8_t *data, size_t length)
{
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < length; i++)
    {
        crc ^= data[i];
        for (int j = 0; j < 8; j++)
        {
            crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : (crc >> 1);
        }
    }
    return crc;
}

void processModbusFrame(const uint8_t *frame, size_t length)
{
    if (length < 8 || frame[0] != MODBUS_ADDRESS)
        return;

    uint16_t crc = Modbus_CRC16(frame, length - 2);
    uint16_t crcReceived = frame[length - 2] | (frame[length - 1] << 8);
    if (crc != crcReceived)
        return;

    uint8_t func = frame[1];
    uint16_t reg = (frame[2] << 8) | frame[3];
    int16_t val = (int16_t)((frame[4] << 8) | frame[5]); // signed 16bit

    if (func == 0x06)
    { // Write Single Register
        switch (reg)
        {
        case 0x005E:
            motorParam.rev_0 = (val < 0);
            motorParam.sv_0 = abs(val);
            motorRun(0);
            break;

        case 0x0060:
            motorParam.acc_rpm_0 = val;
            break;

        case 0x0062:
            motorParam.acc_rpm_0 = val;
            break;

        case 0x0064:
            motorParam.rev_0 = (val != 0);
            break;

        case 0x0066:
            if (val == 1)
                motorRun(0);
            break;
        }
    }
}

uint16_t holdingRegisters[10] = {0};

void handleModbusRequest()
{
    uint8_t buffer[64];
    size_t len = RS485_Read(buffer, sizeof(buffer), 100);
    if (len < 8 || buffer[0] != MODBUS_ADDRESS)
        return;

    uint16_t crc = Modbus_CRC16(buffer, len - 2);
    uint16_t crcReceived = buffer[len - 2] | (buffer[len - 1] << 8);
    if (crc != crcReceived)
        return;

    uint8_t func = buffer[1];
    uint16_t regAddr = (buffer[2] << 8) | buffer[3];

    if (func == 0x03 && buffer[4] == 0x00 && buffer[5] == 0x01)
    {
        // Read 1 register
        if (regAddr < 10)
        {
            uint16_t val = holdingRegisters[regAddr];
            uint8_t response[7] = {
                MODBUS_ADDRESS, 0x03, 0x02,
                (uint8_t)(val >> 8), (uint8_t)(val & 0xFF), 0, 0};
            uint16_t crcResp = Modbus_CRC16(response, 5);
            response[5] = crcResp & 0xFF;
            response[6] = crcResp >> 8;
            RS485_Write(response, 7);
        }
    }

    if (func == 0x06)
    {
        uint16_t val = (buffer[4] << 8) | buffer[5];
        if (regAddr < 10)
        {
            holdingRegisters[regAddr] = val;
            RS485_Write(buffer, 8); // Echo back write confirmation
        }
    }
}