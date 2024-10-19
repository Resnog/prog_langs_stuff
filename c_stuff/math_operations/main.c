#include <stdio.h>
#include <stdlib.h>

#include "linalg.h"

int main(){
    
    // Matrix A
    struct intMat a = rand_int_mat2(3,3,0,10);
    // Matrix B
    struct intMat b = rand_int_mat2(3,3,0,10);
    // Matrix C
    struct intMat c = add_mat2d(a,b);    

    print_mat2d(a);
    print_mat2d(b);
    print_mat2d(c);


    return 0x01;
}