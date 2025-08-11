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
    int pivot_index = 0;
    int* pivot = arr + (n - 1);
    int* partition_point = arr;
    int tmp = 0; 
    int swaps = 0; 

    if( n == 0 || n == 1) {
        return swaps;
    }
    
    /* Iterate until the end of the array */
    for(int* i = arr; i != (arr + (n - 1)); i++){
        if(*i < *pivot){
            if(i == pivot){continue;}
            /* Move the element to the partition point and jump one address */
            tmp = *partition_point;
            *partition_point = *i;
            *i = tmp;
            partition_point++;
            /* Keep track of the swaps to have some metric to measure the performance */
            swaps++;
        } 
    }

    /* Swap the pivot value with the partition point*/
    tmp = *partition_point;
    *partition_point = *pivot;
    *pivot = tmp;

    /* Calculate the new pivot index*/
    pivot_index = partition_point - arr;

    /*Left array*/
    swaps += quickSort(arr, pivot_index);
    /*Right array*/
    swaps += quickSort(arr + pivot_index + 1,
                       n - pivot_index - 1);

    return swaps;
}
