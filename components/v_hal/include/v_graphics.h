#ifndef V_GRAPHICS_H
#define V_GRAPHICS_H

#include "v_display.h"
#include "v_config.h"


void gfx_draw_pixel(int x, int y, uint16_t color);

void gfx_draw_line(int x0, int y0, int x1, int y1, uint16_t color);

void gfx_fill_rect(int x, int y, int w, int h, uint16_t color);

void gfx_clear(uint16_t color);

#endif
