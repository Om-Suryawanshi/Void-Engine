#ifndef V_DISPLAY_H
#define V_DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

void display_init(void);

//void display_set_window(int x, int y, int w, int h);

//void display_push_color(uint16_t color);

//void display_push_pixels(uint16_t *colors, int count);

//void display_fill_rect(int x, int y, int w, int h, uint16_t color);

void display_draw(void); // Sends the entire frame buffer to the screen via DMA

#endif
