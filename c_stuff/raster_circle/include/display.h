#include <stdint.h>
#include <stdlib.h>
#include "point.h"
#include "circle.h"

#define RESOLUTION 21

#ifndef DISPLAY_H
#define DISPLAY_H

uint8_t** display_init(void);

void display_print(uint8_t** matrix);

void display_draw_full_circle(uint8_t** display, circle *c);
 #endif // DISPLAY_H