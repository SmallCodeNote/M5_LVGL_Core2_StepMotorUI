#ifndef EEZ_LVGL_UI_STRUCTS_H
#define EEZ_LVGL_UI_STRUCTS_H

#include "eez-flow.h"


#if defined(EEZ_FOR_LVGL)

#include <stdint.h>
#include <stdbool.h>

#include "vars.h"

using namespace eez;

enum FlowStructures {
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG = 16384
};

enum FlowArrayOfStructures {
    FLOW_ARRAY_OF_STRUCTURE_STEP_MOTOR_CONFIG = 81920
};

enum StepMotorConfigFlowStructureFields {
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_PPR = 0,
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_ACCELERATION = 1,
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_SV = 2,
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_TITLE = 3,
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_DIRECTION_REV = 4,
    FLOW_STRUCTURE_STEP_MOTOR_CONFIG_NUM_FIELDS
};

struct StepMotorConfigValue {
    Value value;
    
    StepMotorConfigValue() {
        value = Value::makeArrayRef(FLOW_STRUCTURE_STEP_MOTOR_CONFIG_NUM_FIELDS, FLOW_STRUCTURE_STEP_MOTOR_CONFIG, 0);
    }
    
    StepMotorConfigValue(Value value) : value(value) {}
    
    operator Value() const { return value; }
    
    operator bool() const { return value.isArray(); }
    
    int PPR() {
        return value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_PPR].getInt();
    }
    void PPR(int PPR) {
        value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_PPR] = IntegerValue(PPR);
    }
    
    int Acceleration() {
        return value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_ACCELERATION].getInt();
    }
    void Acceleration(int Acceleration) {
        value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_ACCELERATION] = IntegerValue(Acceleration);
    }
    
    int SV() {
        return value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_SV].getInt();
    }
    void SV(int SV) {
        value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_SV] = IntegerValue(SV);
    }
    
    const char *Title() {
        return value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_TITLE].getString();
    }
    void Title(const char *Title) {
        value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_TITLE] = StringValue(Title);
    }
    
    bool DirectionRev() {
        return value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_DIRECTION_REV].getBoolean();
    }
    void DirectionRev(bool DirectionRev) {
        value.getArray()->values[FLOW_STRUCTURE_STEP_MOTOR_CONFIG_FIELD_DIRECTION_REV] = BooleanValue(DirectionRev);
    }
};

typedef ArrayOf<StepMotorConfigValue, FLOW_ARRAY_OF_STRUCTURE_STEP_MOTOR_CONFIG> ArrayOfStepMotorConfigValue;


#endif

#endif /*EEZ_LVGL_UI_STRUCTS_H*/
