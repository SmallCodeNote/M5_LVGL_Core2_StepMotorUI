#include <Arduino.h>
#include <lvgl.h>

#ifndef MY_COMMON_CODE_H
#define MY_COMMON_CODE_H

//Set to your screen resolution and rotation//
#define TFT_HOR_RES   320
#define TFT_VER_RES   240
#define TFT_ROTATION  LV_DISPLAY_ROTATION_0

//LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 15 * (LV_COLOR_DEPTH / 8))
extern uint32_t draw_buf[]; //uint32_t draw_buf[DRAW_BUF_SIZE / 4];


void my_device_initialize(M5GFX &gfx);

void my_disp_flush_callback(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map);
void my_touchpad_read_callback(lv_indev_t *indev, lv_indev_data_t *data);

#endif