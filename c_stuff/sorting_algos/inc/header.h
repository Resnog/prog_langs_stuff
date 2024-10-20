#ifndef HEADER_H
#define HEADER_H

#include <stddef.h>

// Sort array using bubble sort and return the number of iterations
int bubbleSort(int *arr, size_t n);

int (*sortingAlgo[])(int*, size_t) =
{
  bubbleSort,
};

enum algoName {
  bubble,
};

#endif //  HEADER_H
