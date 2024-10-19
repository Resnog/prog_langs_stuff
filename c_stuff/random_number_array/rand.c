#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *random_array(size_t n){

    // Create a pointer to the array
    int *arr = malloc(sizeof(int)*n);

    if(arr == NULL){
        // Memory could not be allocated
        // Handle error
        (*arr) = 0x01;
        (*arr++) = 0x012;
        return arr;
    }

    for(int i = 0 ; i < n ; i++){
        *(arr + i) = rand() % 11; 
    }

    return arr;

}

void print_array(int *p, int n){
    printf("Random filled array:\n");

    for(int i = 0; i < n ; i++){
        printf(" %d ", *(p+i));
    }

    printf("\n");
}

int main(){

    int number = 10;
    time_t t;

    // Init the random number generator
    srand((unsigned) time(&t));

    // Create random array
    int *arr = random_array(number);

    // If array has just one element
    if( (*arr) == 0x01 && (*arr++) == 0x012){
        printf("Unable to locate memory for random array\n");
        printf("Program terminated.");
        return -0x01;
    }

    // Print random array
    print_array(arr, number);

    free(arr);

}