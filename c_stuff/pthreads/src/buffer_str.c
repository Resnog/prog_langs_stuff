#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include "buffer_str.h"

static inline void word_buffer_clean(void){
    memset(word_buffer, buffer_empty_char, sizeof(word_buffer));
}

void _remove_new_line(char* word){
    for(int i = 0; i < buffer_size; i++){
        if(word[i] == '\n'
            || word[i] == '\0'){
            word[i] = buffer_empty_char;}
    }
}

void copy_word_to_buffer(char* word){

        _remove_new_line(word);

        write_index = write_index % word_number;
        memcpy( word_buffer + buffer_size*write_index, 
                word, 
                sizeof(word));
        memset(word, 0, sizeof(word));
        write_index++;
}

void word_buffer_print(void){
    for(int i = 0; i < buffer_size * word_number; i++){
        printf("%c", word_buffer[i]);
    }
    printf("\n");
}

void word_buffer_get_last_word(){
    char last_word[buffer_size];
    memcpy( last_word,
            word_buffer + buffer_size*(write_index - 1),
            sizeof(last_word));
    printf("Word >> %s", last_word);
}

void word_buffer_thread(void){
    pthread_t thread;
    pthread_create(&thread, NULL, (void*)word_buffer_get_last_word, NULL);
    pthread_join(thread, NULL);
}