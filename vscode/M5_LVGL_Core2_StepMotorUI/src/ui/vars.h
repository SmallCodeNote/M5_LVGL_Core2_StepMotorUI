#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_CONFIG_TARGET_ITEM_INDEX = 0,
    FLOW_GLOBAL_VARIABLE_CONFIG_TARGET_ITEM_LIST = 1,
    FLOW_GLOBAL_VARIABLE_CONFIG_TARGET_MOROT_INDEX = 2,
    FLOW_GLOBAL_VARIABLE_MOTORS_CONF = 3,
    FLOW_GLOBAL_VARIABLE_MOTORS_PV = 4,
    FLOW_GLOBAL_VARIABLE_MOTORS_RUN = 5
};

// Native global variables

extern int32_t get_var_motor_pv_0();
extern void set_var_motor_pv_0(int32_t value);
extern int32_t get_var_motor_pv_1();
extern void set_var_motor_pv_1(int32_t value);
extern int32_t get_var_motor_pv_2();
extern void set_var_motor_pv_2(int32_t value);
extern int32_t get_var_motor_sv_0();
extern void set_var_motor_sv_0(int32_t value);
extern int32_t get_var_motor_sv_1();
extern void set_var_motor_sv_1(int32_t value);
extern int32_t get_var_motor_sv_2();
extern void set_var_motor_sv_2(int32_t value);
extern bool get_var_motor_run_0();
extern void set_var_motor_run_0(bool value);
extern bool get_var_motor_run_1();
extern void set_var_motor_run_1(bool value);
extern bool get_var_motor_run_2();
extern void set_var_motor_run_2(bool value);
extern int32_t get_var_motor_ppr_0();
extern void set_var_motor_ppr_0(int32_t value);
extern int32_t get_var_motor_ppr_1();
extern void set_var_motor_ppr_1(int32_t value);
extern int32_t get_var_motor_ppr_2();
extern void set_var_motor_ppr_2(int32_t value);
extern int32_t get_var_motor_acceleration_0();
extern void set_var_motor_acceleration_0(int32_t value);
extern int32_t get_var_motor_acceleration_1();
extern void set_var_motor_acceleration_1(int32_t value);
extern int32_t get_var_motor_acceleration_2();
extern void set_var_motor_acceleration_2(int32_t value);
extern bool get_var_motor_direction_rev_0();
extern void set_var_motor_direction_rev_0(bool value);
extern bool get_var_motor_direction_rev_1();
extern void set_var_motor_direction_rev_1(bool value);
extern bool get_var_motor_direction_rev_2();
extern void set_var_motor_direction_rev_2(bool value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/