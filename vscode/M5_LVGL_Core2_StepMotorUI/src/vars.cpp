#include "ui/vars.h"

// Process Value
int32_t motor_pv_0;
int32_t motor_pv_1;
int32_t motor_pv_2;

extern "C" int32_t get_var_motor_pv_0() { return motor_pv_0; }
extern "C" int32_t get_var_motor_pv_1() { return motor_pv_1; }
extern "C" int32_t get_var_motor_pv_2() { return motor_pv_2; }

extern "C" void set_var_motor_pv_0(int32_t value) { motor_pv_0 = value; }
extern "C" void set_var_motor_pv_1(int32_t value) { motor_pv_1 = value; }
extern "C" void set_var_motor_pv_2(int32_t value) { motor_pv_2 = value; }

// Set Value
int32_t motor_sv_0;
int32_t motor_sv_1;
int32_t motor_sv_2;

extern "C" int32_t get_var_motor_sv_0() { return motor_sv_0; }
extern "C" int32_t get_var_motor_sv_1() { return motor_sv_1; }
extern "C" int32_t get_var_motor_sv_2() { return motor_sv_2; }

extern "C" void set_var_motor_sv_0(int32_t value) { motor_sv_0 = value; }
extern "C" void set_var_motor_sv_1(int32_t value) { motor_sv_1 = value; }
extern "C" void set_var_motor_sv_2(int32_t value) { motor_sv_2 = value; }

// Motor RUN Flag
bool motor_run_0;
bool motor_run_1;
bool motor_run_2;

extern "C" bool get_var_motor_run_0() { return motor_run_0; }
extern "C" bool get_var_motor_run_1() { return motor_run_1; }
extern "C" bool get_var_motor_run_2() { return motor_run_2; }

extern "C" void set_var_motor_run_0(bool value) { motor_run_0 = value; }
extern "C" void set_var_motor_run_1(bool value) { motor_run_1 = value; }
extern "C" void set_var_motor_run_2(bool value) { motor_run_2 = value; }

int32_t motor_acceleration_0;
int32_t motor_acceleration_1;
int32_t motor_acceleration_2;

extern "C" int32_t get_var_motor_acceleration_0() { return motor_acceleration_0; }
extern "C" int32_t get_var_motor_acceleration_1() { return motor_acceleration_1; }
extern "C" int32_t get_var_motor_acceleration_2() { return motor_acceleration_2; }

extern "C" void set_var_motor_acceleration_0(int32_t value) { motor_acceleration_0 = value; }
extern "C" void set_var_motor_acceleration_1(int32_t value) { motor_acceleration_1 = value; }
extern "C" void set_var_motor_acceleration_2(int32_t value) { motor_acceleration_2 = value; }

bool motor_direction_rev_0;
bool motor_direction_rev_1;
bool motor_direction_rev_2;

extern "C" bool get_var_motor_direction_rev_0() { return motor_direction_rev_0; }
extern "C" bool get_var_motor_direction_rev_1() { return motor_direction_rev_1; }
extern "C" bool get_var_motor_direction_rev_2() { return motor_direction_rev_2; }

extern "C" void set_var_motor_direction_rev_0(bool value) { motor_direction_rev_0 = value; }
extern "C" void set_var_motor_direction_rev_1(bool value) { motor_direction_rev_1 = value; }
extern "C" void set_var_motor_direction_rev_2(bool value) { motor_direction_rev_2 = value; }

int32_t motor_ppr_0;
int32_t motor_ppr_1;
int32_t motor_ppr_2;

extern "C" int32_t get_var_motor_ppr_0() { return motor_ppr_0; }
extern "C" int32_t get_var_motor_ppr_1() { return motor_ppr_1; }
extern "C" int32_t get_var_motor_ppr_2() { return motor_ppr_2; }

extern "C" void set_var_motor_ppr_0(int32_t value) { motor_ppr_0 = value; }
extern "C" void set_var_motor_ppr_1(int32_t value) { motor_ppr_1 = value; }
extern "C" void set_var_motor_ppr_2(int32_t value) { motor_ppr_2 = value; }


int32_t sensor_value;
int32_t sensor_top_left_x;
int32_t sensor_top_left_y;
int32_t sensor_bottom_right_x;
int32_t sensor_bottom_right_y;
int32_t sensor_interval;

extern "C" int32_t get_var_sensor_value() { return sensor_value; }
extern "C" void set_var_sensor_value(int32_t value) { sensor_value = value; }

extern "C" int32_t get_var_sensor_top_left_x() { return sensor_top_left_x; }
extern "C" void set_var_sensor_top_left_x(int32_t value) { sensor_top_left_x = value; }

extern "C" int32_t get_var_sensor_top_left_y() { return sensor_top_left_y; }
extern "C" void set_var_sensor_top_left_y(int32_t value) { sensor_top_left_y = value; }

extern "C" int32_t get_var_sensor_bottom_right_x() { return sensor_bottom_right_x; }
extern "C" void set_var_sensor_bottom_right_x(int32_t value) { sensor_bottom_right_x = value; }

extern "C" int32_t get_var_sensor_bottom_right_y() { return sensor_bottom_right_y; }
extern "C" void set_var_sensor_bottom_right_y(int32_t value) { sensor_bottom_right_y = value; }

extern "C" int32_t get_var_sensor_interval() { return sensor_interval;}
extern "C" void set_var_sensor_interval(int32_t value) { sensor_interval = value;}
