#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "circle.h"
#include "point.h"

#define RESOLUTION (41)

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

void display_draw_circle(uint8_t** display, circle *c) {
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
