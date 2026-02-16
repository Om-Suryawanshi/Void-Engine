#ifndef V_INPUT_H
#define V_INPUT_H

#include <stdint.h>
#include <stdbool.h>

#define INPUT_UP    (1 << 0)
#define INPUT_DOWN  (1 << 1)
#define INPUT_LEFT  (1 << 2)
#define INPUT_RIGHT (1 << 3)
#define INPUT_A     (1 << 4)
#define INPUT_B     (1 << 5)


void input_init(void);
uint8_t input_get(void);

#endif
