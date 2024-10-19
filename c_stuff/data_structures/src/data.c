#include <stdio.h>
#include <stdlib.h>
#include "data.h"

data* ll_new(void){
    return (data*) malloc(sizeof(data));
}

