#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "some_math_threads.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add_number(void *ptr) {
	pthread_mutex_lock(&mutex);
	int* num = (int*) ptr;
	main_number += (*num);
	printf("Thread %d added number, main now %d\n", pthread_self(), main_number);
	pthread_mutex_unlock(&mutex);
}

void *multiply_number(void *ptr) {
	pthread_mutex_lock(&mutex);
	int* num = (int*) ptr;
	main_number *= (*num);		
	printf("Thread %d multiplied number, main now %d\n", pthread_self(), main_number);
	pthread_mutex_unlock(&mutex);
}

void add_and_multiply_two_numbers()
{

  pthread_t thread1, thread2, thread3;
  int num1 = 10;
  int num2 = 5;
  int iret1, iret2;

  // Create two threads with different messages
  iret1 = pthread_create( &thread1, NULL, add_number, (void*) &num1);
  iret2 = pthread_create( &thread2, NULL, multiply_number, (void*) &num2);

  // Wait for threads to terminate execution
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("Thread1 returned : %d \n", iret1);
  printf("Thread2 returned : %d \n", iret2);

}
