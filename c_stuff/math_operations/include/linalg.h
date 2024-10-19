#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mat2D
struct intMat
{
    int r;      // Number of rows
    int c;      // Number of columns
    int **arr;  // Double Pointer to values
};

// Init integer matrix 
struct intMat init_int_matrix(int r,int c){
    
    struct intMat mat;

    // Set the number of rows and colums
    mat.r = r;
    mat.c = c;

    // Create the 2D matrix allocating dynamically
    mat.arr = (int **)malloc(mat.r* sizeof(int *));
    for (int i = 0; i<mat.r ; i++ ){
        mat.arr[i] = (int*)malloc(mat.c*sizeof(int));
    }  

    return mat;
   // This is a comment I added in VIM 
}

// Zeros filled Matrix 2D
struct intMat zeros_int_mat2(int r, int c)
{
    struct intMat mat = init_int_matrix(r,c);
    
    // Fill the matrix with zeros
    for(int i = 0; i < mat.r; i++){ // Iter r
        for(int j = 0; j < mat.c; j++ ){ // Iter c
            mat.arr[i][j] = 0;
        }
    }

    return mat;
}

// Random filled Matrix 2D
struct intMat rand_int_mat2(int r, int c, int min, int max)
{

    struct intMat mat = init_int_matrix(r,c);
    
    // Init the random number generator
    time_t t;
    srand((unsigned) time(&t));

    for(int i = 0; i < r; i++){ // Iter r
        for(int j = 0; j < c; j++ ){ // Iter c
            mat.arr[i][j] = rand() % (max-min+1) +min;
        }
    }

    // Return a double pointer of a 2D array filled with random numbers
    return mat;
}

// Print Matrix 2D
void print_mat2d(struct intMat mat){

    for (int i = 0; i < mat.r; i++)
    {

        printf("\n|"); // Separate for each new line
        for (int j = 0; j < mat.c; j++)
        {
            printf(" %d ", mat.arr[i][j]);
        }
        printf("|");
    }
    
    printf("\n");

}

// Add 2 2D matrices
struct intMat add_mat2d( struct intMat a, struct intMat b){
    
    
    // Check if the matrices can be added
    if ( ( a.c == b.c) && (a.r == b.r) ){
        struct intMat mat = init_int_matrix(a.r,a.c);

    // Add each element of each dimension       
    for(int i = 0; i < mat.r; i++){ // Iter r
        for(int j = 0; j < mat.c; j++ ){ // Iter c
            mat.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
        // Return result
        return mat;
        
    }else{
        // Return a initilized (3,3) matrix in memory but empty
        printf("Can't add matrices A and B\n");
        return init_int_matrix(3,3);
    }
}

