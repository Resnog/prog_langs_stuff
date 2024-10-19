#include <stdio.h>
#include <stdlib.h>

#ifndef DATA_H
#define DATA_H

typedef struct {
    void* data;
    size_t data_size;
}data;

data* data_new(void);

#endif //  DATA_H
