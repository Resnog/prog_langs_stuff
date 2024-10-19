#ifndef BUFFER_STR_H
#define BUFFER_STR_H

#include <stddef.h>

enum buffer_symbol { buffer_empty_char = '#'};

const size_t buffer_size = 16;
const size_t word_number = 3;

char word_buffer[buffer_size * word_number];
size_t write_index = 0;

static inline void word_buffer_clean(void);

void _remove_line(char* word);

void word_buffer_get_last_word(void);

void word_buffer_thread(void);

void word_buffer_print(void);

void word_buffer_thread(void);

#endif // BUFFER_STR_H