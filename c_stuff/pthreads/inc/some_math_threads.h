#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#ifndef MATH_THREADS_H
#define MATH_THREADS_H

int main_number = 0;

void *add_number(void *ptr);

void *multiply_number(void *ptr);

void add_and_multiply_two_numbers();

#endif // MATH_THREADS_H
