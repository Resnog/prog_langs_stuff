#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include "buffer_str.h"
#include "string_printing.h"
#include "some_math_threads.h"

static inline void user_buffer_clean(void){
    memset(word_buffer, buffer_empty_char, sizeof(word_buffer));
}

void user_buffer_get_all_words(){

    char word[buffer_size];
    memset(word, 0, sizeof(word));
    printf("User buffer contents:\n");
    for(int i = 0; i < word_number; i++)
    {
        memcpy(word, 
               word_buffer + buffer_size * i, 
               sizeof(word));
        printf("Word %d:", i + 1);
        printf("%s\n", word);
        memset(word, 0, sizeof(word));
    }
    printf("\n");
}


void user_buffer_print(){
    for(int i = 0; i < buffer_size * word_number; i++){
        printf("%c", word_buffer[i]);
    }
    printf("\n");
}

void remove_new_line(char* word){
    for(int i = 0; i < buffer_size; i++){
        if(word[i] == '\n'
            || word[i] == '\0'){
            word[i] = buffer_empty_char;}
    }
}

void copy_word_to_buffer(char* word){

        remove_new_line(word);

        write_index = write_index % word_number;
        memcpy( word_buffer + buffer_size*write_index, 
                word, 
                sizeof(word));
        memset(word, 0, sizeof(word));
        write_index++;
}

void get_last_word(){
    char last_word[buffer_size];
    memcpy( last_word,
            word_buffer + buffer_size*(write_index - 1),
            sizeof(last_word));
    printf("Word >> %s", last_word);
}

int main() {

    char word[buffer_size];
    memset(word, 0, sizeof(word));

    user_buffer_clean();

    while(1)
    {

        word_buffer_print();
        fgets(word, buffer_size - 1, stdin);

        if(strcmp(word, "Exit\n") == 0){
            printf("Input loop ending\n");
            break;
        }

        printf("Word is : %s | Write index %lu\n", word, buffer_size*write_index);

        copy_word_to_buffer(word);

    };

    word_buffer_get_last_word();

    user_buffer_get_all_words();

    return 0x00;
}
