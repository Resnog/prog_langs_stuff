#include <stdio.h>
#include <pthread.h>

void *print_string(void *arg)
{
    char* string = (char*)arg;
    printf("%s",string);
    return NULL;
}

void print_three_words(){

  pthread_t t1, t2, t3;
  int iret1, iret2, iret3;

  printf("The result of calling print_three_words should be:\n Apple  Banana  Coconut \n");

  pthread_create(&t1, NULL, print_string, " Apple ");
  pthread_create(&t2, NULL, print_string, " Banana ");
  pthread_create(&t3, NULL, print_string, " Coconut ");

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);

  printf("\n");

}
