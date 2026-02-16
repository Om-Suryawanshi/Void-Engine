#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "v_graphics.h"
#include "v_colors.h"

static const char *TAG = "VOID_ENGINE";

void app_main(void)
{
    ESP_LOGI(TAG, "Init Framebuffer Mode...");
    display_init();


    while(1)
    {
        // 1. Draw Phase (All happens in RAM - Instant)
        gfx_clear(V_BLACK);
        
        // No delays needed here! No Watchdog risk!
        gfx_draw_line(0, 0, 128, 160, V_YELLOW);
        gfx_draw_line(128, 0, 0, 160, V_YELLOW);
        
        gfx_fill_rect(50, 50, 30, 30, V_RED);

        // 2. Present Phase (Blast to Screen)
        // This takes ~30ms at 40MHz SPI
        display_draw();
        
        // Cap framerate (optional)
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
