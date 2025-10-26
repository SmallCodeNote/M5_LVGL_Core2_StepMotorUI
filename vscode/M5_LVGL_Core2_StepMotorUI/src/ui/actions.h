#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_motor_sv_update_0(lv_event_t * e);
extern void action_motor_sv_update_1(lv_event_t * e);
extern void action_motor_sv_update_2(lv_event_t * e);
extern void action_motor_run_update_0(lv_event_t * e);
extern void action_motor_run_update_1(lv_event_t * e);
extern void action_motor_run_update_2(lv_event_t * e);
extern void action_motor_param_update_0(lv_event_t * e);
extern void action_motor_param_update_1(lv_event_t * e);
extern void action_motor_param_update_2(lv_event_t * e);
extern void action_sensor_param_update(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/