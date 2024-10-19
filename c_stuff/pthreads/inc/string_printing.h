#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifndef STRING_PRINTING_H
#define STRING_PRINTING_H

void *print_string(void *arg);

void print_three_words();

#endif // STRING_PRINTING_H
