#include <stdio.h>
#include <stdint.h>

enum user_cmd{
    EXIT = 0,
    PRINT_LAST_WORD = 1,
    PRINT_ALL_WORDS = 2,
};

const size_t user_cmd_buffer_size = 16;
uint8_t user_cmd_buffer[user_cmd_buffer_size];

static inline void _init_user_cmd_buffer(void){
    memset(user_cmd_buffer, 0, sizeof(user_cmd_buffer));
}

void menu_print(void){
    printf("Menu:\n");
    printf("1. Print last word\n");
    printf("2. Print all words\n");
    printf("3. Enter words\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void menu_thread(void){
    menu_print();
    fgets(user_cmd_buffer, user_cmd_buffer_size, stdin);
}