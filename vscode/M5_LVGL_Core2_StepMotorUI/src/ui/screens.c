#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_screen_top_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_screen_config_motor_textarea_config_motor_ppr(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 2, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_screen_config_motor_textarea_config_motor_acceleration(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 5, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_screen_config_motor_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_screen_config_motor_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 10, 3, value, "Failed to assign Checked state");
        }
    }
}

static void event_handler_cb_screen_input_keyboard_integer_keyboard_input_keyboard_integer(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 1, e);
    }
}

static void event_handler_cb_screen_input_keyboard_integer_textarea_input_keyboard_integer(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 2, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_screen_input_sv_arc_config_motor_sv(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_arc_get_value(ta);
            assignIntegerProperty(flowState, 0, 3, value, "Failed to assign Value in Arc widget");
        }
    }
}

static void event_handler_cb_screen_input_sv_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_screen_input_sv_userwidget_motorinfo_button_switch_run_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 9, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_screen_sensor_view_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_screen_sensor_view_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_textarea_config_sensor_top_left_x(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 0, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_textarea_config_sensor_top_left_y(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 3, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_textarea_config_sensor_bottom_right_x(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 5, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_textarea_config_sensor_bottom_right_y(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 7, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_textarea_config_sensor_bottom_right_y_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 13, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 13, 0, e);
    }
}

static void event_handler_cb_screen_sensor_config_input_keyboard_integer_keyboard_input_keyboard_integer_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_READY) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 0, e);
    }
    if (event == LV_EVENT_CANCEL) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 0, 1, e);
    }
}

static void event_handler_cb_screen_sensor_config_input_keyboard_integer_textarea_input_keyboard_integer_1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            const char *value = lv_textarea_get_text(ta);
            assignStringProperty(flowState, 2, 3, value, "Failed to assign Text in Textarea widget");
        }
    }
}

static void event_handler_cb_userwidget_motorinfo_userwidget_motorinfo_button_switch_run(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            bool value = lv_obj_has_state(ta, LV_STATE_CHECKED);
            assignBooleanProperty(flowState, 1, 3, value, "Failed to assign Checked state");
        }
    }
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

static void event_handler_cb_userwidget_motorinfo_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_userwidget_motorinfo_userwidget_motorinfo_label_sv(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

void create_screen_screen_top() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_top = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // userwidget_motorinfo_x
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.userwidget_motorinfo_x = obj;
            lv_obj_set_pos(obj, 60, 0);
            lv_obj_set_size(obj, 260, 80);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_userwidget_motorinfo(obj, getFlowState(flowState, 0), 8);
        }
        {
            // userwidget_motorinfo_y
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.userwidget_motorinfo_y = obj;
            lv_obj_set_pos(obj, 60, 80);
            lv_obj_set_size(obj, 260, 80);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_userwidget_motorinfo(obj, getFlowState(flowState, 2), 17);
        }
        {
            // userwidget_motorinfo_z
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.userwidget_motorinfo_z = obj;
            lv_obj_set_pos(obj, 60, 160);
            lv_obj_set_size(obj, 260, 80);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_userwidget_motorinfo(obj, getFlowState(flowState, 3), 26);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 2, 188);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_top_obj0, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj7 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_screen_top();
}

void tick_screen_screen_top() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    tick_user_widget_userwidget_motorinfo(getFlowState(flowState, 0), 8);
    tick_user_widget_userwidget_motorinfo(getFlowState(flowState, 2), 17);
    tick_user_widget_userwidget_motorinfo(getFlowState(flowState, 3), 26);
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj7;
            lv_label_set_text(objects.obj7, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_config_motor() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_config_motor = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // label_config_motor_title
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_config_motor_title = obj;
            lv_obj_set_pos(obj, 0, 21);
            lv_obj_set_size(obj, 92, 165);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            add_style_style_label_title(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff071f83), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // textarea_config_motor_ppr
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_motor_ppr = obj;
            lv_obj_set_pos(obj, 205, 0);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_config_motor_textarea_config_motor_ppr, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 106, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "PulsePer\nRotation");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 106, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Acceleration\nRPM/sec");
        }
        {
            // textarea_config_motor_acceleration
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_motor_acceleration = obj;
            lv_obj_set_pos(obj, 205, 54);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_config_motor_textarea_config_motor_acceleration, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Title");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 2, 198);
            lv_obj_set_size(obj, 100, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_config_motor_obj1, LV_EVENT_ALL, flowState);
            add_style_style_button_ok(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_style_button_label(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 106, 121);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Direction\nRev");
        }
        {
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 213, 117);
            lv_obj_set_size(obj, 100, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_config_motor_obj2, LV_EVENT_ALL, flowState);
        }
    }
    
    tick_screen_screen_config_motor();
}

void tick_screen_screen_config_motor() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_config_motor_title);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_config_motor_title;
            lv_label_set_text(objects.label_config_motor_title, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_motor_ppr);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_motor_ppr);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_motor_ppr;
            lv_textarea_set_text(objects.textarea_config_motor_ppr, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_motor_acceleration);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_motor_acceleration);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_motor_acceleration;
            lv_textarea_set_text(objects.textarea_config_motor_acceleration, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.obj2, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj2;
            if (new_val) lv_obj_add_state(objects.obj2, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.obj2, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_input_keyboard_integer() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_input_keyboard_integer = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // keyboard_input_keyboard_integer
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keyboard_input_keyboard_integer = obj;
            lv_obj_set_pos(obj, 0, 42);
            lv_obj_set_size(obj, 320, 198);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_input_keyboard_integer_keyboard_input_keyboard_integer, LV_EVENT_ALL, flowState);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_ITEMS | LV_STATE_DEFAULT);
        }
        {
            // textarea_input_keyboard_integer
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_input_keyboard_integer = obj;
            lv_obj_set_pos(obj, 160, 0);
            lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_input_keyboard_integer_textarea_input_keyboard_integer, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            // label_input_keyboard_integer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_input_keyboard_integer = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 160, 42);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
        }
    }
    lv_keyboard_set_textarea(objects.keyboard_input_keyboard_integer, objects.textarea_input_keyboard_integer);
    
    tick_screen_screen_input_keyboard_integer();
}

void tick_screen_screen_input_keyboard_integer() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_input_keyboard_integer);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_input_keyboard_integer);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_input_keyboard_integer;
            lv_textarea_set_text(objects.textarea_input_keyboard_integer, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_input_keyboard_integer);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_input_keyboard_integer;
            lv_label_set_text(objects.label_input_keyboard_integer, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_input_sv() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_input_sv = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // arc_config_motor_sv
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.arc_config_motor_sv = obj;
            lv_obj_set_pos(obj, 110, 20);
            lv_obj_set_size(obj, 200, 200);
            lv_arc_set_range(obj, 1, 150);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_input_sv_arc_config_motor_sv, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj10 = obj;
                    lv_obj_set_pos(obj, 50, 64);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 50, 40);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "SV");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 50, 120);
                    lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "RPM");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 2, 198);
            lv_obj_set_size(obj, 80, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_input_sv_obj3, LV_EVENT_ALL, flowState);
            add_style_style_button_ok(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_style_button_label(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 1, 1);
            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 1, 58);
            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // userwidget_motorinfo_button_switch_run_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.userwidget_motorinfo_button_switch_run_1 = obj;
            lv_obj_set_pos(obj, 2, 121);
            lv_obj_set_size(obj, 80, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_input_sv_userwidget_motorinfo_button_switch_run_1, LV_EVENT_ALL, flowState);
            add_style_style_button_switch(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // userwidget_motorinfo_button_switch_run_label_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.userwidget_motorinfo_button_switch_run_label_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 80, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 4, 34);
            lv_obj_set_size(obj, 100, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "PV");
        }
    }
    
    tick_screen_screen_input_sv();
}

void tick_screen_screen_input_sv() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    {
        int32_t new_val = evalIntegerProperty(flowState, 0, 3, "Failed to evaluate Value in Arc widget");
        int32_t cur_val = lv_arc_get_value(objects.arc_config_motor_sv);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.arc_config_motor_sv;
            lv_arc_set_value(objects.arc_config_motor_sv, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj10);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj10;
            lv_label_set_text(objects.obj10, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj11);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj11;
            lv_label_set_text(objects.obj11, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj12);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj12;
            lv_label_set_text(objects.obj12, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(objects.userwidget_motorinfo_button_switch_run_1, LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.userwidget_motorinfo_button_switch_run_1;
            if (new_val) lv_obj_add_state(objects.userwidget_motorinfo_button_switch_run_1, LV_STATE_CHECKED);
            else lv_obj_clear_state(objects.userwidget_motorinfo_button_switch_run_1, LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 10, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.userwidget_motorinfo_button_switch_run_label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.userwidget_motorinfo_button_switch_run_label_1;
            lv_label_set_text(objects.userwidget_motorinfo_button_switch_run_label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_sensor_view() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_sensor_view = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // chart_sensor_view
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.chart_sensor_view = obj;
            lv_obj_set_pos(obj, 60, 0);
            lv_obj_set_size(obj, 260, 200);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 137, 200);
            lv_obj_set_size(obj, 141, 40);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 288, 220);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "mm");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 69, 202);
            lv_obj_set_size(obj, 60, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_view_obj4, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj14 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 2, 202);
            lv_obj_set_size(obj, 60, 36);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_view_obj5, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj15 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_screen_sensor_view();
}

void tick_screen_screen_sensor_view() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj13);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj13;
            lv_label_set_text(objects.obj13, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj14);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj14;
            lv_label_set_text(objects.obj14, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj15);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj15;
            lv_label_set_text(objects.obj15, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_sensor_config() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_sensor_config = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // textarea_config_sensor_topLeftX
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_sensor_top_left_x = obj;
            lv_obj_set_pos(obj, 205, 0);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_textarea_config_sensor_top_left_x, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 133, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "topLeftX");
        }
        {
            // textarea_config_sensor_topLeftY
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_sensor_top_left_y = obj;
            lv_obj_set_pos(obj, 205, 46);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_textarea_config_sensor_top_left_y, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 133, 46);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "topLeftY");
        }
        {
            // textarea_config_sensor_bottomRightX
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_sensor_bottom_right_x = obj;
            lv_obj_set_pos(obj, 205, 93);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_textarea_config_sensor_bottom_right_x, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 133, 93);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "bottom\nRightX");
        }
        {
            // textarea_config_sensor_bottomRightY
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_sensor_bottom_right_y = obj;
            lv_obj_set_pos(obj, 205, 140);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_textarea_config_sensor_bottom_right_y, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 133, 140);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "bottom\nRightY");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 2, 198);
            lv_obj_set_size(obj, 80, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_obj6, LV_EVENT_ALL, flowState);
            add_style_style_button_ok(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_style_button_label(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 4, 30);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "VL53L1X\nCONFIG");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 1, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "TOF");
        }
        {
            // textarea_config_sensor_bottomRightY_1
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_config_sensor_bottom_right_y_1 = obj;
            lv_obj_set_pos(obj, 205, 188);
            lv_obj_set_size(obj, 115, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_textarea_config_sensor_bottom_right_y_1, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 133, 188);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Seensor\nInterval");
        }
    }
    
    tick_screen_screen_sensor_config();
}

void tick_screen_screen_sensor_config() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_sensor_top_left_x);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_sensor_top_left_x);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_sensor_top_left_x;
            lv_textarea_set_text(objects.textarea_config_sensor_top_left_x, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_sensor_top_left_y);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_sensor_top_left_y);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_sensor_top_left_y;
            lv_textarea_set_text(objects.textarea_config_sensor_top_left_y, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 5, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_sensor_bottom_right_x);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_sensor_bottom_right_x);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_sensor_bottom_right_x;
            lv_textarea_set_text(objects.textarea_config_sensor_bottom_right_x, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 7, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_sensor_bottom_right_y);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_sensor_bottom_right_y);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_sensor_bottom_right_y;
            lv_textarea_set_text(objects.textarea_config_sensor_bottom_right_y, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_config_sensor_bottom_right_y_1);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_config_sensor_bottom_right_y_1);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_config_sensor_bottom_right_y_1;
            lv_textarea_set_text(objects.textarea_config_sensor_bottom_right_y_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_screen_sensor_config_input_keyboard_integer() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_sensor_config_input_keyboard_integer = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // keyboard_input_keyboard_integer_1
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keyboard_input_keyboard_integer_1 = obj;
            lv_obj_set_pos(obj, 0, 42);
            lv_obj_set_size(obj, 320, 198);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_input_keyboard_integer_keyboard_input_keyboard_integer_1, LV_EVENT_ALL, flowState);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_ITEMS | LV_STATE_DEFAULT);
        }
        {
            // textarea_input_keyboard_integer_1
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_input_keyboard_integer_1 = obj;
            lv_obj_set_pos(obj, 160, 0);
            lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
            lv_textarea_set_max_length(obj, 8);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_sensor_config_input_keyboard_integer_textarea_input_keyboard_integer_1, LV_EVENT_ALL, flowState);
            add_style_style_textarea_inputnum(obj);
        }
        {
            // label_input_keyboard_integer_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_input_keyboard_integer_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 160, 42);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
        }
    }
    lv_keyboard_set_textarea(objects.keyboard_input_keyboard_integer_1, objects.textarea_input_keyboard_integer_1);
    
    tick_screen_screen_sensor_config_input_keyboard_integer();
}

void tick_screen_screen_sensor_config_input_keyboard_integer() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Textarea widget");
        const char *cur_val = lv_textarea_get_text(objects.textarea_input_keyboard_integer_1);
        uint32_t max_length = lv_textarea_get_max_length(objects.textarea_input_keyboard_integer_1);
        if (strncmp(new_val, cur_val, max_length) != 0) {
            tick_value_change_obj = objects.textarea_input_keyboard_integer_1;
            lv_textarea_set_text(objects.textarea_input_keyboard_integer_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.label_input_keyboard_integer_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.label_input_keyboard_integer_1;
            lv_label_set_text(objects.label_input_keyboard_integer_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_userwidget_motorinfo(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // userwidget_motorinfo_button_switch_run
            lv_obj_t *obj = lv_button_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 194, 10);
            lv_obj_set_size(obj, 60, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_userwidget_motorinfo_userwidget_motorinfo_button_switch_run, LV_EVENT_ALL, flowState);
            add_style_style_button_switch(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // userwidget_motorinfo_button_switch_run_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 58, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // userwidget_motorinfo_label_pv
            lv_obj_t *obj = lv_label_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
            lv_obj_set_pos(obj, 76, 0);
            lv_obj_set_size(obj, 110, 52);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
            lv_obj_set_pos(obj, 2, 10);
            lv_obj_set_size(obj, 30, 60);
            lv_obj_add_event_cb(obj, event_handler_cb_userwidget_motorinfo_obj0, LV_EVENT_ALL, flowState);
            add_style_style_button_switch_enable(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // userwidget_motorinfo_label_sv
            lv_obj_t *obj = lv_label_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
            lv_obj_set_pos(obj, 112, 45);
            lv_obj_set_size(obj, 74, 29);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_add_event_cb(obj, event_handler_cb_userwidget_motorinfo_userwidget_motorinfo_label_sv, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 90, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "SV");
        }
        {
            // userwidget_motorinfo_label_title
            lv_obj_t *obj = lv_label_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
            lv_obj_set_pos(obj, 40, 10);
            lv_obj_set_size(obj, 35, 30);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
        }
        {
            // userwidget_motorinfo_label_motorindex
            lv_obj_t *obj = lv_label_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
            lv_obj_set_pos(obj, 41, 40);
            lv_obj_set_size(obj, 35, 19);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_label_set_text(obj, "");
        }
    }
}

void tick_user_widget_userwidget_motorinfo(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    {
        bool new_val = evalBooleanProperty(flowState, 1, 3, "Failed to evaluate Checked state");
        bool cur_val = lv_obj_has_state(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_STATE_CHECKED);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 0];
            if (new_val) lv_obj_add_state(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_STATE_CHECKED);
            else lv_obj_clear_state(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_STATE_CHECKED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 3]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 3];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 3], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 6, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 4]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 4];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 4], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 7, 3, "Failed to evaluate Disabled state");
        bool cur_val = lv_obj_has_state(((lv_obj_t **)&objects)[startWidgetIndex + 1], LV_STATE_DISABLED);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 1];
            if (new_val) lv_obj_add_state(((lv_obj_t **)&objects)[startWidgetIndex + 1], LV_STATE_DISABLED);
            else lv_obj_clear_state(((lv_obj_t **)&objects)[startWidgetIndex + 1], LV_STATE_DISABLED);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 7]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 7];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 7], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 9, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 2]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 2];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 2], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 5]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 5];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 5], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 6]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 6];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 6], new_val);
            tick_value_change_obj = NULL;
        }
    }
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "screen_top", "screen_config_motor", "screen_input_keyboard_integer", "screen_input_sv", "screen_sensor_view", "screen_sensor_config", "screen_sensor_config_input_keyboard_integer" };
static const char *object_names[] = { "screen_top", "screen_config_motor", "screen_input_keyboard_integer", "screen_input_sv", "screen_sensor_view", "screen_sensor_config", "screen_sensor_config_input_keyboard_integer", "userwidget_motorinfo_x", "userwidget_motorinfo_x__userwidget_motorinfo_button_switch_run", "userwidget_motorinfo_x__obj0", "userwidget_motorinfo_x__userwidget_motorinfo_label_sv", "userwidget_motorinfo_x__userwidget_motorinfo_button_switch_run_label", "userwidget_motorinfo_x__userwidget_motorinfo_label_pv", "userwidget_motorinfo_x__userwidget_motorinfo_label_title", "userwidget_motorinfo_x__userwidget_motorinfo_label_motorindex", "userwidget_motorinfo_x__obj1", "userwidget_motorinfo_y", "userwidget_motorinfo_y__userwidget_motorinfo_button_switch_run", "userwidget_motorinfo_y__obj0", "userwidget_motorinfo_y__userwidget_motorinfo_label_sv", "userwidget_motorinfo_y__userwidget_motorinfo_button_switch_run_label", "userwidget_motorinfo_y__userwidget_motorinfo_label_pv", "userwidget_motorinfo_y__userwidget_motorinfo_label_title", "userwidget_motorinfo_y__userwidget_motorinfo_label_motorindex", "userwidget_motorinfo_y__obj1", "userwidget_motorinfo_z", "userwidget_motorinfo_z__userwidget_motorinfo_button_switch_run", "userwidget_motorinfo_z__obj0", "userwidget_motorinfo_z__userwidget_motorinfo_label_sv", "userwidget_motorinfo_z__userwidget_motorinfo_button_switch_run_label", "userwidget_motorinfo_z__userwidget_motorinfo_label_pv", "userwidget_motorinfo_z__userwidget_motorinfo_label_title", "userwidget_motorinfo_z__userwidget_motorinfo_label_motorindex", "userwidget_motorinfo_z__obj1", "obj0", "textarea_config_motor_ppr", "textarea_config_motor_acceleration", "obj1", "obj2", "keyboard_input_keyboard_integer", "obj3", "userwidget_motorinfo_button_switch_run_1", "obj4", "obj5", "textarea_config_sensor_top_left_x", "textarea_config_sensor_top_left_y", "textarea_config_sensor_bottom_right_x", "textarea_config_sensor_bottom_right_y", "obj6", "textarea_config_sensor_bottom_right_y_1", "keyboard_input_keyboard_integer_1", "obj7", "label_config_motor_title", "obj8", "obj9", "textarea_input_keyboard_integer", "label_input_keyboard_integer", "arc_config_motor_sv", "userwidget_motorinfo_button_switch_run_label_1", "obj10", "obj11", "obj12", "chart_sensor_view", "obj13", "obj14", "obj15", "textarea_input_keyboard_integer_1", "label_input_keyboard_integer_1" };
static const char *style_names[] = { "style_button_OK", "style_button_label", "style_button_switch", "style_button_switch_enable", "style_label_title", "style_textarea_inputnum" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_screen_top,
    tick_screen_screen_config_motor,
    tick_screen_screen_input_keyboard_integer,
    tick_screen_screen_input_sv,
    tick_screen_screen_sensor_view,
    tick_screen_screen_sensor_config,
    tick_screen_screen_sensor_config_input_keyboard_integer,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_screen_top();
    create_screen_screen_config_motor();
    create_screen_screen_input_keyboard_integer();
    create_screen_screen_input_sv();
    create_screen_screen_sensor_view();
    create_screen_screen_sensor_config();
    create_screen_screen_sensor_config_input_keyboard_integer();
}
