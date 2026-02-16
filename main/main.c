#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "v_graphics.h"
#include "v_display.h"
#include "v_config.h"
#include "v_colors.h"
#include "v_input.h"

static const char *TAG = "VOID_ENGINE";

void app_main(void)
{
    ESP_LOGI(TAG, "Init...");
    display_init();
    input_init();

    int px = 64;
    int py = 80;
    int speed = 2;

    while(1)
    {
      uint8_t keys = input_get();
      if (keys & INPUT_UP) py -= speed;
      if (keys & INPUT_DOWN) py += speed;
      if (keys & INPUT_LEFT) px += speed;
      if (keys & INPUT_RIGHT) px -= speed;

      uint16_t color = (keys & INPUT_A) ? V_RED : V_YELLOW;

      if(px < 0) px = 0;
      if(px > 120) px = 120;
      if(py < 0) py = 0;
      if(py > 150) py = 150;

      gfx_clear(V_BLACK);
      gfx_fill_rect(px, py, 8, 8, color);
      display_draw();

      vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}
