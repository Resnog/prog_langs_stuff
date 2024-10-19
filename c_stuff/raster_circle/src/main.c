#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#include "point.h"
#include "circle.h"
#include "display.h"

#define DEBUG 0

enum bool {
  false = 0, 
  true = 1,
};

// MAIN EXECUTION
int main() {

  // Display matrix 
  uint8_t** display_matrix = display_init();
  
  // Circle to draw
  circle *c = circle_create_new_circle(13, 11, 7);   

  printf("Radius point -> X: %u Y: %u\n", c->center.x, c->center.y);
  display_matrix[c->center.x][c->center.y] = 1;

  circle_add_traces(c); 
 
  display_draw_full_circle(display_matrix, c);
  
  display_print(display_matrix); 
 
  return 0x00;
}
