#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *screen_top;
    lv_obj_t *screen_config_motor;
    lv_obj_t *screen_input_keyboard_integer;
    lv_obj_t *screen_input_sv;
    lv_obj_t *userwidget_motorinfo_x;
    lv_obj_t *userwidget_motorinfo_x__userwidget_motorinfo_button_switch_run;
    lv_obj_t *userwidget_motorinfo_x__obj0;
    lv_obj_t *userwidget_motorinfo_x__userwidget_motorinfo_label_sv;
    lv_obj_t *userwidget_motorinfo_x__userwidget_motorinfo_button_switch_run_label;
    lv_obj_t *userwidget_motorinfo_x__userwidget_motorinfo_label_pv;
    lv_obj_t *userwidget_motorinfo_x__userwidget_motorinfo_label_title;
    lv_obj_t *userwidget_motorinfo_x__userwidget_motorinfo_label_motorindex;
    lv_obj_t *userwidget_motorinfo_x__obj1;
    lv_obj_t *userwidget_motorinfo_y;
    lv_obj_t *userwidget_motorinfo_y__userwidget_motorinfo_button_switch_run;
    lv_obj_t *userwidget_motorinfo_y__obj0;
    lv_obj_t *userwidget_motorinfo_y__userwidget_motorinfo_label_sv;
    lv_obj_t *userwidget_motorinfo_y__userwidget_motorinfo_button_switch_run_label;
    lv_obj_t *userwidget_motorinfo_y__userwidget_motorinfo_label_pv;
    lv_obj_t *userwidget_motorinfo_y__userwidget_motorinfo_label_title;
    lv_obj_t *userwidget_motorinfo_y__userwidget_motorinfo_label_motorindex;
    lv_obj_t *userwidget_motorinfo_y__obj1;
    lv_obj_t *userwidget_motorinfo_z;
    lv_obj_t *userwidget_motorinfo_z__userwidget_motorinfo_button_switch_run;
    lv_obj_t *userwidget_motorinfo_z__obj0;
    lv_obj_t *userwidget_motorinfo_z__userwidget_motorinfo_label_sv;
    lv_obj_t *userwidget_motorinfo_z__userwidget_motorinfo_button_switch_run_label;
    lv_obj_t *userwidget_motorinfo_z__userwidget_motorinfo_label_pv;
    lv_obj_t *userwidget_motorinfo_z__userwidget_motorinfo_label_title;
    lv_obj_t *userwidget_motorinfo_z__userwidget_motorinfo_label_motorindex;
    lv_obj_t *userwidget_motorinfo_z__obj1;
    lv_obj_t *textarea_config_motor_ppr;
    lv_obj_t *textarea_config_motor_acceleration;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *keyboard_input_keyboard_integer;
    lv_obj_t *obj2;
    lv_obj_t *userwidget_motorinfo_button_switch_run_1;
    lv_obj_t *label_config_motor_title;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *textarea_input_keyboard_integer;
    lv_obj_t *label_input_keyboard_integer;
    lv_obj_t *arc_config_motor_sv;
    lv_obj_t *userwidget_motorinfo_button_switch_run_label_1;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_SCREEN_TOP = 1,
    SCREEN_ID_SCREEN_CONFIG_MOTOR = 2,
    SCREEN_ID_SCREEN_INPUT_KEYBOARD_INTEGER = 3,
    SCREEN_ID_SCREEN_INPUT_SV = 4,
};

void create_screen_screen_top();
void tick_screen_screen_top();

void create_screen_screen_config_motor();
void tick_screen_screen_config_motor();

void create_screen_screen_input_keyboard_integer();
void tick_screen_screen_input_keyboard_integer();

void create_screen_screen_input_sv();
void tick_screen_screen_input_sv();

void create_user_widget_userwidget_motorinfo(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_userwidget_motorinfo(void *flowState, int startWidgetIndex);

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/