#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "animal.h"
#include "animal_p.h"

typedef struct {
    animal_t animal;
}duck_t;

// Define a new behavior for the cat's sound
void __duck_sound(void* this_ptr) {
    animal_t* animal= (animal_t*)this_ptr;
    printf("%s: Quack\n", animal->name);
}

// Memory allocator
duck_t* duck_new() {
    return (duck_t*)malloc(sizeof(duck_t));
}

// Constructor
void duck_ctor(duck_t* duck) {
    animal_ctor((struct animal_t*)duck);
    strcpy(duck->animal.name, "Duck");
    // Point to the new behaviour function, this will 
    // override actual inherited implementation 
    duck->animal.sound_func = __duck_sound;
}

// Destructor
void duck_dtor(duck_t* duck) {
    animal_dtor((struct animal_t*)duck);
}
