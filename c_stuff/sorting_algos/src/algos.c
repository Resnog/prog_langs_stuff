#include <stddef.h>
#include <stdio.h>
#include "header.h"
#include <stdbool.h>

void swap_left(size_t element, int* arr, size_t size){
    
}

void swap_right(size_t element, int* arr, size_t size){
    
}

int bubbleSort(int *arr, size_t n){
    int iterations = 0;
    int swaps = 0;
    int temp = 0;

    while(1){
        swaps = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if( arr[i] > arr[i+1] )
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swaps++;
            }
        }

        iterations++;

        if (swaps == 0){
            break;
        }

    }
    return iterations;
}

int quickSort(int *arr, size_t n){
    int iterations = 0;
    int swaps = 0;
    int* pivot = arr + (n - 1);
    int* bigger = NULL;
    int temp = 0; 
    
    while(1){
        swaps = 0;

        // Iterate until the pivot is reached
        for(int* i = arr; i != pivot; i++){
            if(*(i) > *(pivot)){
                bigger = i;
            } else {
                temp = *(i);
                *(i) = *(i + 1);
                *(i + 1) = temp;
                swaps++;
            }
        }
        iterations++;
        break;
        //if(swaps == 0){break;}
    }

    
    
}
