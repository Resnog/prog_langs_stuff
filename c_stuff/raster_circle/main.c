#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define RESOLUTION 41
#define DEBUG 0

enum bool {
  false = 0, 
  true = 1,
};
// POINT 
/*
  A 2D point in a discrete space
*/
typedef struct{
  int x;
  int y;
}point;

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


// CIRCLE CLASS
// Center point of the circle
//
typedef struct{
  point center;
  int radius;
  unsigned int segment_points_num;
  point* segment_points;
}circle;

circle* circle_create_new_circle(int x, int y, int r) {

    circle *c = (circle*) malloc(sizeof(circle)); 

    c->center.x = x;
    c->center.y = y;
    c->radius = r;
    c->segment_points_num = 0;
    c->segment_points = NULL;

    return c;
}

int circle_radius_error(point p, circle* c) {
  return (int) fabs(pow(p.x - c->center.x,2) + pow(p.y-c->center.y,2) - pow(c->radius,2));
}

point circle_get_starting_point(const circle *c ){
  point p = {
    .x = c->center.x,
    .y = c->center.y - c->radius,
  };
  return p;
}

int circle_desicion_criteria(point p, circle *c) {
  
  int res = circle_radius_error(p,c) + 1 + (p.y << 1); // RE(x,y) + (2y + 1)
  res = (res << 1); // 2[RE(x,y) + (1 -2x)] 
  res += (1 - (p.x << 1)); // 2[RE(x,y) + (2y + 1)] + (1-2x)
    if( res > 0) {
      return true;
    } else {
      return false;
    }
 }

const unsigned int circle_get_max_y_len(circle *c){
  return (unsigned int)(cos(M_PI_4)*c->radius);
}

void circle_alloc_traces(circle *c, unsigned int len){
  c->segment_points_num = len;
  c->segment_points = (point*) malloc( len*sizeof(point));
}

void circle_add_traces(circle *c) {
  // Get the 45° X length for 1/8 of the traces of the circle
  unsigned int len = circle_get_max_y_len(c) + 1;
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



// DISPLAY CLASS

uint8_t** display_init(void) {
  uint8_t** matrix =  (uint8_t**) calloc(RESOLUTION, sizeof(uint8_t*));
  for (int i = 0; i < RESOLUTION ; i++) {
    matrix[i] = (uint8_t*) calloc(RESOLUTION, sizeof(uint8_t));
  }
  return matrix;
}

void display_print(uint8_t** matrix) {
  for(int x = 0; x < RESOLUTION; x++) {
    printf("\n");
    for(int y = 0; y < RESOLUTION; y++) {
      printf("%d ", matrix[y][x]);
    }
  }
}

void display_draw_full_circle(uint8_t** display, circle *c) {
  
  // Display radius points
  display[c->center.x-c->radius][c->center.y] = 1;  
  display[c->center.x+c->radius][c->center.y] = 1;  
  display[c->center.x][c->center.y-c->radius] = 1;  
  display[c->center.x][c->center.y+c->radius] = 1;  
  // Get mirrored points for main circle segment
  point* mirrored_segment = circle_mirror_main_segment(c, NULL);
  // Loop through the main segment traces
  for(int i = 0; i < c->segment_points_num ; i++ ) {
      display[c->segment_points[i].x][c->segment_points[i].y] = 3;    
      display[mirrored_segment[i].x][mirrored_segment[i].y] = 4;    
  }
  point res = { .x=0,.y=0};
  // Rotate circle segment points
 for(int j = 0; j <= c->segment_points_num; j++){
    for(int i = 0; i < c->segment_points_num; i++){
      res = point_rotate_n_degress(&c->segment_points[i], &c->center, 90.0 * j);
      display[res.x][res.y] = 2;    
     
      res = point_rotate_n_degress(&mirrored_segment[i], &c->center, 90.0 * j);
      display[res.x][res.y] = 2;    
    }
  } 
}

circle mainCircle = {
    .center.x = RESOLUTION/2,
    .center.y = RESOLUTION/2,
    .radius = RESOLUTION/2 - 5,
    .segment_points = NULL,
    .segment_points_num = 0,
};

  
// MAIN EXECUTION
int main() {

  // Display matrix 
  uint8_t** display_matrix = display_init();
  
  // Circle to draw
  circle *c = &mainCircle;//circle_create_new_circle(13, 11, 7);   

  printf("Radius point -> X: %u Y: %u\n", c->center.x, c->center.y);
  display_matrix[c->center.x][c->center.y] = 1;

  circle_add_traces(c); 
 
  display_draw_full_circle(display_matrix, c);
  
  display_print(display_matrix); 
 
  return 0x00;
}
