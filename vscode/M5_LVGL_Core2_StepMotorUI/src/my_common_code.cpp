#include <M5Unified.h>
#include "my_common_code.h"


static uint32_t my_tick_callback(void);

uint32_t draw_buf[DRAW_BUF_SIZE / 4];

#if LV_USE_LOG != 0
void my_print_callback(lv_log_level_t level, const char *buf)
{
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
#endif

void my_device_initialize(M5GFX &gfx)
{
  lv_init();
  lv_tick_set_cb(my_tick_callback);

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print_callback);
#endif

  lv_display_t *disp;
  disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
  lv_display_set_flush_cb(disp, my_disp_flush_callback);
  lv_display_set_buffers(disp, draw_buf, nullptr, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

  //Initialize the input device driver//
  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); //Touchpad should have POINTER type//
  lv_indev_set_read_cb(indev, my_touchpad_read_callback);
}

// LVGL calls it when a rendered image needs to copied to the display//
void my_disp_flush_callback(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
  uint32_t width = (area->x2 - area->x1 + 1);
  uint32_t height = (area->y2 - area->y1 + 1);
  lv_draw_sw_rgb565_swap(px_map, width * height);
  M5.Display.pushImageDMA<uint16_t>(area->x1, area->y1, width, height, (uint16_t *)px_map);
  lv_display_flush_ready(disp);
}

void my_touchpad_read_callback(lv_indev_t *indev, lv_indev_data_t *data)
{
  lgfx::touch_point_t tp;
  M5.update();
  if (M5.Display.getTouch(&tp))
  {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = tp.x;
    data->point.y = tp.y;
  }
  else
  {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

static uint32_t my_tick_callback(void)
{
  return millis();
}