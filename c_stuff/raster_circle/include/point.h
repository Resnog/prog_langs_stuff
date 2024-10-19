#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#ifndef POINT_H
#define POINT_H

typedef struct{
  int x;
  int y;
}point;

unsigned int point_distance(point a, point b);

point point_rotate_n_degress(point *p, point *rotation_point, double rotation_angle);

#endif  // POINT_H
