#include <Arduino.h>
#include <M5Unified.h>
#include "ui/ui.h"
#include "ui/eez-flow.h"
#include "my_common_code.h"

/*
extern const uint8_t assets[];
extern const uint32_t assetsSize;
extern lv_obj_t *objects[];
extern const size_t numObjects;
extern const ext_img_desc_t images[];
extern const size_t numImages;
extern ActionExecFunc actions[];
*/

void setup() {
    String LVGL_Arduino = "LVGL information : ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  M5.begin();
  Serial.begin(115200);
  Serial.println(LVGL_Arduino);
  my_device_initialize(M5.Display);

  lv_init();
  ui_init();

}

void loop() {
  M5.update();
  //lv_timer_handler();
  lv_task_handler();
  ui_tick();
  delay(5);
}