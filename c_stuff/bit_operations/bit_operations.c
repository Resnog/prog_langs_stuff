/**
 * @author      : segonzal (segonzal@$HOSTNAME)
 * @file        : 
 * @created     : Wednesday Dec 21, 2022 09:00:11 EET
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>


#define BIT(bit) (1U << (bit))
#define BYTE_LEN 8

typedef uint8_t byte_mask; 

typedef uint32_t bgapi_msg_header;

// Defined enum for masking some memory space
enum bit_number{
    bit_0 = 0,
    bit_1 = 1,
    bit_2 = 2,
    bit_3 = 3,
};

int get_mask(enum bit_number n_bit) {
    // Use an OR operation on each desired classification,
    // this will become a constant after compilation.
    int mask = (1U << bit_0)
               | (1U << bit_1)
               | (1U << bit_2)
               | (1U << bit_3);
    // Now return the value of an AND operation, which is in 
    // turn a few machine instructions, this is efficient.
    return ( n_bit & mask );
}

// Kerrighan's bit counting algorithm, quite nice
int count_bits(int n){
    
    unsigned int count = 0;
    
    while(n!=0){
      n = n&(n-1);
      count++;
    }
  return count;
}

int* get_ones_and_zeros_array(size_t n) {
    
    int* arr = (int*) malloc(sizeof(n));
    
    for(int i = 0; i < n; i++) {
        if(i%2 == 0){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }
    
    return arr;
}

void bit_loop(int n) {
    for(int i = 0; i < n; i++) {
        printf("<%d> ", 1U << i);
    }
    printf("\n");
}

void print_arr(int* arr, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}

uint32_t* arr_into_128bit_number(uint32_t* arr) {
    uint32_t *res = (uint32_t*)malloc( 4 * sizeof(uint32_t));
    
    return res;
}


#define LCD_DISPLAY_SIZE 24

uint8_t** get_display_pattern(uint8_t diagonal){
    uint8_t** display = (uint8_t**) malloc(LCD_DISPLAY_SIZE* sizeof(uint8_t*));  
    for(int i =0; i < LCD_DISPLAY_SIZE; i++) {
        display[i] = (uint8_t*)malloc(LCD_DISPLAY_SIZE*sizeof(uint8_t));
    }
    
    uint8_t toogle = 0;

  for(int i = 0; i < LCD_DISPLAY_SIZE; i++) {
      for(int j = 0; j < LCD_DISPLAY_SIZE; j++){
          if(toogle == 0) {
              display[i][j] = 0;
              toogle = 1;
          } else {
              display[i][j] = 1;
              toogle = 0;
          }
      }
        
        if(diagonal==1){
            if(toogle==1){ toogle = 0;}
            else { toogle = 1;}
        }
    }
 return display;    
}

void print_map(uint8_t** map) {
    for(int i = 0; i < LCD_DISPLAY_SIZE; i++) {
        printf("|");
          for(int j = 0; j < LCD_DISPLAY_SIZE; j++){
              printf("%d|" , map[i][j]);
          }
        printf("\n");
    }
}
    
  
void array_to_bitmap() {
    uint8_t data[8] = {0, 1, 0, 1, 1, 0, 1, 0};
    uint8_t res = 0;
    uint8_t mask_result = 0;
    printf("\n");
    for(int i = 0; i < 8; i++) {
        if(data[i] == 1) {
            res += (1U << i);
        }
    }
    printf("Result %u", res);
}


/*
 * Show bytes in a little endian format to the user, so each time when compiling
 * the user can know how the word should be stored
 * */
void bytes_to_bitmap() {
    uint8_t data[BYTE_LEN][BYTE_LEN] = {{1,0,0,0,0,0,0,1},
                                        {0,0,0,0,0,0,1,0},
                                        {0,0,0,0,0,1,0,0},
                                        {0,0,0,0,1,0,0,0},
                                        {0,0,0,1,0,0,0,0},
                                        {0,0,1,0,0,0,0,0},
                                        {0,1,0,0,0,0,0,0},
                                        {1,0,0,0,0,0,0,0}};

    uint8_t* lcd_data =  (uint8_t*) malloc(sizeof(uint8_t) );
        for(int i = 0; i < BYTE_LEN; i++) {
            for(int j = BYTE_LEN; j >= 0; j--) {
                    if(data[i][j] == 1){
                        lcd_data[i] =  lcd_data[i] | (1U << j) ;
                    }
                }
            printf("Byte %d is %.2x\n", i, lcd_data[i]);
            }
    printf("\n\n");
}

uint8_t reverse_byte(uint8_t v) { 
    uint8_t r = v; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end
        for (v >>= 1; v; v >>= 1)
        {   
          r <<= 1;
          r |= v & 1;
          s--;
        }
    r <<= s; // shift when v's highest bits are zero
    
    return r;
}

uint8_t** fill_bitmap(uint8_t** map) {

    // Allocate a bitmap for the LCD_DISPLAY_SIZE lines of the display
    uint8_t** bitmap = (uint8_t**) malloc(LCD_DISPLAY_SIZE* sizeof(uint8_t*));
    for(int i = 0; i < LCD_DISPLAY_SIZE; i++) {
        bitmap[i] = (uint8_t*)malloc( LCD_DISPLAY_SIZE/BYTE_LEN*sizeof(uint8_t));
    }
    printf("Bytes : %d\n", LCD_DISPLAY_SIZE/BYTE_LEN);
    uint8_t byte;
    // Iterate over each line
    for(int line = 0; line < LCD_DISPLAY_SIZE; line++){
        byte = 0;
            // Iterate over each value on the map
            for(int col = 0; col < LCD_DISPLAY_SIZE; col++){
                if(map[line][col] == 1){
                    bitmap[line][byte] += (1U << (col % BYTE_LEN) );
                    // printf("Line :%d Col: %d Byte: %d -> Value : 0x%.2x\n", line, col, byte,bitmap[line][byte]);
                }
                // Jump to next byte
                if(col % BYTE_LEN == 0 && col) {
                    byte++;
                }
            }
        // break;
        }
    
    
    return bitmap;
}


void clear_bitmap(uint8_t** bitmap) {
    for(int i = 0; i < LCD_DISPLAY_SIZE;i++) {
        memset( bitmap[i], 0, LCD_DISPLAY_SIZE/BYTE_LEN * sizeof(uint8_t));
    }
}


void lcd_test(){
    // lcd_display_fill_pattern(1);
    
    printf("In: %d, Out: %d\n", 1, reverse_byte(1) );
    
    uint8_t** map = get_display_pattern(0);
    uint8_t** bitmap = fill_bitmap(map);
    
    printf("Data\n");
    for(int i = 0; i < LCD_DISPLAY_SIZE; i++) {
        for(int j = 0; j < LCD_DISPLAY_SIZE; j++) {
            printf("%.2d ", map[i][j]);
        }
        printf("\n");
    }

    printf("Bitmap\n");
    for(int i = 0; i < LCD_DISPLAY_SIZE; i++) {
        for(int j = 0; j < LCD_DISPLAY_SIZE/BYTE_LEN; j++) {
            printf("0x%.2x ", bitmap[i][j]);
        }
        printf("\n");
    }
    
    clear_bitmap(bitmap);
        
    printf("Bitmap\n");
    for(int i = 0; i < LCD_DISPLAY_SIZE; i++) {
        for(int j = 0; j < LCD_DISPLAY_SIZE/BYTE_LEN; j++) {
            printf("0x%.2x ", bitmap[i][j]);
        }
        printf("\n");
    }

}

#define BGAPI_MSG_HEADER_CMD_ID_FIELD    (24)
#define BGAPI_MSG_HEADER_CLASS_ID_FIELD    (16)
#define BGAPI_MSG_HEADER_PAYLOAD_LEN_FIELD    (8)

#define BGAPI_MSG_HEADER_MSG_TYPE_MASK   (0x80)
#define BGAPI_MSG_HEADER_PAYLOAD_LEN_HIGEST_3_BITS   (0x07)

#define BGAPI_DEVICE_TYPE_BLE    (0x10)
#define BGAPI_DEVICE_TYPE_MESH    (0x14)
#define BGAPI_MSG_TYPE_EVENT             (1)
#define BGAPI_MSG_TYPE_CMD_OR_CMD_RSP    (0)

typedef struct _bgapi_header_data {
    uint8_t  device_type;
    uint8_t  message_type;
    uint8_t  payload_len;
    uint8_t  class_id;
    uint8_t  msg_id;
} bgapi_header_data;

bgapi_header_data bgapi_msg_get_header_data(uint32_t header){
    bgapi_header_data header_data;
    
    header_data.device_type = 0;
    header_data.message_type = 0;
    header_data.payload_len = 0;
    header_data.class_id = 0;
    header_data.msg_id = 0;

    return header_data;
}

uint32_t bgapi_msg_create_header(bgapi_header_data header_data) {
    uint32_t header = 0; 


    header = header | ( ((uint32_t) header_data.class_id << BGAPI_MSG_HEADER_CLASS_ID_FIELD));
    header = header | ( ((uint32_t) header_data.msg_id)) << BGAPI_MSG_HEADER_CMD_ID_FIELD;

    return header;
}

int main()
{
    // int var = 0x0F0F;
    
    
    //bit_loop(5);

    //int *arr = get_ones_and_zeros_array(10);
    //print_arr(arr, 10);
    
    //printf("\nSize of uint32_t %lu\n", sizeof(uint32_t));
    // BGAPI MSG header
    bgapi_header_data header_data = {
        .device_type = 0x07,
        .message_type = 1,
        .payload_len = 0x123,
        .class_id = 0x11,
        .msg_id = 0x22,
    };
    
    //bytes_to_bitmap();
    bgapi_msg_header header = bgapi_msg_create_header(header_data); 

    // Write a 4 bytes packer header
    uint8_t class_id = 0x11;
    uint8_t msg_id = 0x22;
    uint16_t payload_len = 0x0735;
    header = header | ( (uint32_t)  BGAPI_DEVICE_TYPE_BLE);
    header = header | ( (uint32_t)  BGAPI_MSG_TYPE_EVENT);
    header = header | ( (uint32_t) ((payload_len & 0xFF) << BGAPI_MSG_HEADER_PAYLOAD_LEN_FIELD ));
    header = header | ( (uint32_t) (((payload_len >> 8 ) & BGAPI_MSG_HEADER_PAYLOAD_LEN_HIGEST_3_BITS ) << 5 ));
    header = header | ( ((uint32_t) class_id << BGAPI_MSG_HEADER_CLASS_ID_FIELD));
    header = header | ( ((uint32_t) msg_id)) << BGAPI_MSG_HEADER_CMD_ID_FIELD;
    // Decode a 4 bytes packet header
    

    //printf("PayLen  : 0x%08x\n", header & (0xFF << BGAPI_MSG_HEADER_PAYLOAD_LOWEST_8_LEN_FIELD) );
    printf("Class ID: 0x%08x\n", header & (0xFF << BGAPI_MSG_HEADER_CLASS_ID_FIELD) );
    printf("Msg   ID: 0x%08x\n", header & (0xFF << BGAPI_MSG_HEADER_CMD_ID_FIELD) );
    printf("Debug   : 0x%08x\n", ( (uint32_t) (((payload_len >> 8 ) & BGAPI_MSG_HEADER_PAYLOAD_LEN_HIGEST_3_BITS ) << 5 )) );

    
    return 0x00;
}
    

