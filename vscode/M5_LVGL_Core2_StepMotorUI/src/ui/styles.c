#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: style_button_OK
//

void add_style_style_button_ok(lv_obj_t *obj) {
    (void)obj;
};

void remove_style_style_button_ok(lv_obj_t *obj) {
    (void)obj;
};

//
// Style: style_button_label
//

void init_style_style_button_label_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_20);
};

lv_style_t *get_style_style_button_label_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_style_button_label_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_style_button_label(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_style_button_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_style_button_label(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_style_button_label_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: style_button_switch
//

void init_style_style_button_switch_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xfff44336));
};

lv_style_t *get_style_style_button_switch_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_style_button_switch_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_style_button_switch(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_style_button_switch_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_style_button_switch(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_style_button_switch_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: style_button_switch_enable
//

void init_style_style_button_switch_enable_MAIN_DISABLED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff7e8b96));
};

lv_style_t *get_style_style_button_switch_enable_MAIN_DISABLED() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_style_button_switch_enable_MAIN_DISABLED(style);
    }
    return style;
};

void add_style_style_button_switch_enable(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_style_button_switch_enable_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

void remove_style_style_button_switch_enable(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_style_button_switch_enable_MAIN_DISABLED(), LV_PART_MAIN | LV_STATE_DISABLED);
};

//
// Style: style_label_title
//

void init_style_style_label_title_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_30);
};

lv_style_t *get_style_style_label_title_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_style_label_title_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_style_label_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_style_label_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_style_label_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_style_label_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: style_textarea_inputnum
//

void init_style_style_textarea_inputnum_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_width(style, 2);
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_pad_top(style, 0);
    lv_style_set_text_font(style, &lv_font_montserrat_34);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
};

lv_style_t *get_style_style_textarea_inputnum_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_style_textarea_inputnum_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_style_textarea_inputnum(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_style_textarea_inputnum_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_style_textarea_inputnum(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_style_textarea_inputnum_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_style_button_ok,
        add_style_style_button_label,
        add_style_style_button_switch,
        add_style_style_button_switch_enable,
        add_style_style_label_title,
        add_style_style_textarea_inputnum,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_style_button_ok,
        remove_style_style_button_label,
        remove_style_style_button_switch,
        remove_style_style_button_switch_enable,
        remove_style_style_label_title,
        remove_style_style_textarea_inputnum,
    };
    remove_style_funcs[styleIndex](obj);
}

