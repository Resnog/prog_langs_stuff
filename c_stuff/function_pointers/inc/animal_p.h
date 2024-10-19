#ifndef ANIMAL_P_H
#define ANIMAL_P_H

// Function pointer type for the different morph of animal_sound
typedef void (*sound_func_t)(void*);

// Forward declaration
typedef struct{
    char* name;
    sound_func_t sound_func;
} animal_t;

#endif
