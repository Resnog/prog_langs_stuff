#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "point.h"

unsigned int point_distance(point a, point b) {
  return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
}

point point_rotate_n_degress(point *p, point *rotation_point, double rotation_angle) {
  point res;

  int c = (int) cos((rotation_angle/180.0)*M_PI);
  int s = (int) sin((rotation_angle/180.0)*M_PI);
  int x, y = 0; 
    
  x = p->x - rotation_point->x;
  y = p->y - rotation_point->y;
  
  res.x = (x * c - y *s);
  res.y = (x * s + y *c);
  
  res.x += rotation_point->x;
  res.y += rotation_point->y;
     
  return res;
}

