#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: style_button_OK
void add_style_style_button_ok(lv_obj_t *obj);
void remove_style_style_button_ok(lv_obj_t *obj);

// Style: style_button_label
lv_style_t *get_style_style_button_label_MAIN_DEFAULT();
void add_style_style_button_label(lv_obj_t *obj);
void remove_style_style_button_label(lv_obj_t *obj);

// Style: style_button_switch
lv_style_t *get_style_style_button_switch_MAIN_CHECKED();
void add_style_style_button_switch(lv_obj_t *obj);
void remove_style_style_button_switch(lv_obj_t *obj);

// Style: style_button_switch_enable
lv_style_t *get_style_style_button_switch_enable_MAIN_DISABLED();
void add_style_style_button_switch_enable(lv_obj_t *obj);
void remove_style_style_button_switch_enable(lv_obj_t *obj);

// Style: style_label_title
lv_style_t *get_style_style_label_title_MAIN_DEFAULT();
void add_style_style_label_title(lv_obj_t *obj);
void remove_style_style_label_title(lv_obj_t *obj);

// Style: style_textarea_inputnum
lv_style_t *get_style_style_textarea_inputnum_MAIN_DEFAULT();
void add_style_style_textarea_inputnum(lv_obj_t *obj);
void remove_style_style_textarea_inputnum(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/