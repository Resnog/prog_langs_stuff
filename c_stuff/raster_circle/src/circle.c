#include <math.h>
#include "circle.h"
#include "point.h"
#include "common.h"

circle* circle_create_new_circle(int x, int y, int r) {

    circle *c = (circle*) malloc(sizeof(circle)); 

    c->center.x = x;
    c->center.y = y;
    c->radius = r;
    c->segment_points_num = 0;
    c->segment_points = NULL;

    return c;
}

const unsigned int circle_get_max_y_len(circle *c){
  return (unsigned int)(cos(M_PI_4)*c->radius);
}

void circle_alloc_traces(circle *c, const unsigned int len){
  c->segment_points_num = len;
  c->segment_points = (point*) malloc( len*sizeof(point));
}

int circle_radius_error(point p, const circle *c) {
  return (int) fabs(pow(p.x - c->center.x,2) + pow(p.y-c->center.y,2) - pow(c->radius,2));
}

int circle_desicion_criteria(point p, const circle* c) {
  int res = circle_radius_error(p, c) + 1 + (p.y << 1); // RE(x,y) + (2y + 1)
  res = (res << 1); // 2[RE(x,y) + (1 -2x)] 
  res += (1 - (p.x << 1)); // 2[RE(x,y) + (2y + 1)] + (1-2x)
    if( res > 0) {
      return true;
    } else {
      return false;
    }
 }

point circle_get_starting_point(const circle *c ){
  point p = {
    .x = c->center.x,
    .y = c->center.y - c->radius,
  };
  return p;
}
void circle_add_traces(circle *c) {

  // Get the 45° X length for 1/8 of the traces of the circle
  const unsigned int len = circle_get_max_y_len(c) + 1;
  // Allocate said mamory for the circle
  circle_alloc_traces(c, len); 
  // Get the starting point for the trace calculations
  point p = circle_get_starting_point(c);
  c->segment_points[0].x = p.x;
  c->segment_points[0].y = p.y;
  // Iterate over the points to get the correct traces
  for(int i = 0; i < len; i++){
    if ( circle_desicion_criteria(p, c) == true ) {
      p.y++;
    } 
    p.x++;
    c->segment_points[i].x = p.x;
    c->segment_points[i].y = p.y;
  } 
}
point* circle_mirror_main_segment(circle *c, point* segment) {
    int x, y = 0;
    if(segment == NULL){
      point* circle_segment = c->segment_points;
    }
    point* p = malloc( c->segment_points_num*sizeof(point));
    for(int i = 0; i < c->segment_points_num; i++) {
        x = c->segment_points[i].x - c->center.x;
        x = c->center.x - x;
        p[i].x = x;
        p[i].y = c->segment_points[i].y;
    }
  return p;
}

void circle_debug_points(circle *c) {
  printf("\nCircle point number : %d\n", c->segment_points_num);
  for(int i = 0; i < c->segment_points_num ;i++) {
    printf("\nPoint %d, X: %d Y: %d ",i,c->segment_points[i].x, c->segment_points[i].y);
  }
  printf("\n");
}

