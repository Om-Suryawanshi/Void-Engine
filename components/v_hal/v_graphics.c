#include "v_graphics.h"
#include <stdlib.h>
#include <string.h>
#include "v_colors.h"


extern uint16_t *v_frameBuffer;

void gfx_clear(uint16_t color)
{
  if (!v_frameBuffer) return;
  if (color == V_BLACK)
  {
    memset(v_frameBuffer, 0, V_BUFFER_SIZE * 2);
  }
  else
  {
    uint16_t swapped = (color >> 8) | (color << 8);
    for (int i = 0; i < V_BUFFER_SIZE; i++)
    {
      v_frameBuffer[i] = swapped;
    }
  }
}

void gfx_draw_pixel(int x, int y, uint16_t color)
{
  if (x < 0 || x >= V_DISPLAY_WIDTH || y < 0 || y >= V_DISPLAY_HEIGHT) return;

  v_frameBuffer[y * V_DISPLAY_WIDTH + x] = (color >> 8) | (color << 8);
}

void gfx_draw_line(int x0, int y0, int x1, int y1, uint16_t color)
{
  int dx = abs(x1 - x0);
  int sx = x0 < x1 ? 1 : -1;

  int dy = -abs(y1 - y0);
  int sy = y0 < y1 ? 1 : -1;

  int err = dx + dy, e2;

  while(1)
  {
    gfx_draw_pixel(x0, y0, color);
    
    if (x0 == x1 && y0 == y1) break;
    
    e2 = 2 * err;
    if (e2 >= dy)
    {
      err += dy;
      x0 += sx;
    }

    if (e2 <= dx)
    {
      err += dx;
      y0 += sy;
    }
  }
}

void gfx_draw_rect(int x, int y, int w, int h, uint16_t color)
{
  gfx_draw_line(x, y, x + w - 1, y, color);
  gfx_draw_line(x, y + h - 1, x + w - 1, y + h - 1, color);
  gfx_draw_line(x, y, x, y + h - 1, color);
  gfx_draw_line(x + w - 1, y, x + w - 1, y + h - 1, color);
}

void gfx_fill_rect(int x, int y, int w, int h, uint16_t color)
{
  for (int i = x; i < x + w; i++)
    for (int j = y; j < y + h; j++)
      gfx_draw_pixel(i, j, color);
}
