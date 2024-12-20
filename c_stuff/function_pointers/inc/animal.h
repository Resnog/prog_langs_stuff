#ifndef ANIMAL_H
#define ANIMAL_H

// Forward declaration
struct animal_t;

// Memory allocator
struct animal_t* animal_new();

// Constructor
void animal_ctor(struct animal_t*);

// Destructor
void animal_dtor(struct animal_t*);

// Behaviour functions
void animal_get_name(struct animal_t* animal, char* buffer);
void animal_sound(struct animal_t* animal);

#endif
