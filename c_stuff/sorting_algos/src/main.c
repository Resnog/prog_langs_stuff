#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void print_array(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int random_number(int min_num, int max_num)
{
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
}

int* generate_random_array(size_t size, int min, int max)
{
    int* arr = malloc(size*sizeof(int));
    if(!arr)
    {
        return NULL;
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = random_number(min, max);
    }

    return arr;
}

void printUntil(int* arr, int* pivot){
        for(int* i = arr; i != pivot; i++){
            printf("%d>", *(i));
        }
}

int main(){

    const size_t size = 10;
    const int min = 0;
    const int max = 10;

    srand(time(NULL));


    int* p1 = generate_random_array(size, min, max);
    int* p2 = generate_random_array(size, min, max);
    print_array(p1, size);
    print_array(p2, size);

    int iter = sortingAlgo[quick](p1, size);
    print_array(p1, size);
    printf("Iterations: %d\n", iter);

    iter = sortingAlgo[quick](p2, size);
    print_array(p2, size);
    printf("Iterations: %d\n", iter);

    return 0x00;
}
