#include <stdio.h>
#include "animal.h"
#include "cat.h"
#include "duck.h"

int main() {
  
    struct animal_t* animal = animal_new();
    animal_ctor(animal);
    animal_sound(animal);

    struct cat_t* cat = cat_new();
    cat_ctor(cat);
    animal_sound((struct animal_t*) cat);

    struct duck_t* duck = duck_new();
    duck_ctor(duck);
    animal_sound((struct animal_t*) duck);


    return 0x00;
}
