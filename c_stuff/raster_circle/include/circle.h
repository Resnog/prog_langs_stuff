#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"

#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct{
  point center;
  int radius;
  unsigned int segment_points_num;
  point* segment_points;
}circle;

const unsigned int circle_get_max_y_len(circle *c);

void circle_alloc_traces(circle *c, const unsigned int len);

void circle_add_traces(circle *c);

const unsigned int circle_get_max_y_len(circle *c);

int circle_radius_error(point p, const circle *c);

point* circle_mirror_main_segment(circle *c, point* segment);

int circle_desicion_criteria(point p, const circle *c);

void circle_debug_points(circle *c);

circle* circle_create_new_circle(int x, int y, int r);

#endif  // CIRCLE_H
