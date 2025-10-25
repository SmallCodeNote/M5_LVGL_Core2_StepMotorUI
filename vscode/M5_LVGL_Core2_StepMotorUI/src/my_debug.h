
#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#define DEBUG_PRINTF(fmt, ...) \
  Serial.printf("[DEBUG] %s:%d:%s: " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)

  #define DEBUG_LOG(msg) \
  Serial.printf("[DEBUG] %s:%d:%s: %s\n", __FILE__, __LINE__, __func__, msg)

#define DEBUG_PRINT_LOCATION() \
  Serial.printf("[DEBUG] %s:%d:%s()\n", __FILE__, __LINE__, __func__)

#endif