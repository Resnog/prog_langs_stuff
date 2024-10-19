#include <stdio.h>

void sayHelloWorld(void){
    printf("Hello, World!\n");
}

void lcd_display_fill_pattern_hlines(size_t lcd_display_size_y, size_t lcd_display_size_x){
  int toogle = 0;
  int lcd_display_mat[lcd_display_size_y][lcd_display_size_x];

  for(int i = 0; i < lcd_display_size_y; i++) {
      for(int j = 0; j < lcd_display_size_x; j++){
          if(toogle == 0) {
              lcd_display_mat[i][j] = 0;
          } else {
              lcd_display_mat[i][j] = 1;
          }
          toogle = !toogle;
      }
  }

    for(int i = 0; i < lcd_display_size_y; i++) {
        for(int j = 0; j < lcd_display_size_x; j++){
            printf("%d ", lcd_display_mat[i][j]);
        }
        printf("\n");
    }
}

void lcd_display_fill_pattern_vlines(size_t lcd_display_size_y, size_t lcd_display_size_x){
  int toogle = 0;
  int lcd_display_mat[lcd_display_size_y][lcd_display_size_x];


  for(int i = 0; i < lcd_display_size_y; i++) {
        toogle = !toogle;
      for(int j = 0; j < lcd_display_size_x; j++){
          if(toogle == 1) {
              lcd_display_mat[i][j] = 1;
          } else {
              lcd_display_mat[i][j] = 0;
          }
      }
  }

    for(int i = 0; i < lcd_display_size_y; i++) {
        for(int j = 0; j < lcd_display_size_x; j++){
            printf("%d ", lcd_display_mat[i][j]);
        }
        printf("\n");
    }
}