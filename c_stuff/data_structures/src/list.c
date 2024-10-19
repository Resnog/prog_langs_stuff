#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list* list_new() {

    list* a_list = (list*) malloc(sizeof(list));

    a_list->items= NULL;
    a_list->size = 0; 

    return a_list;
}

list_item* list_new_list_item(void){

    list_item* li = (list_item*) malloc(sizeof(list_item));

    li->data_size = 0;
    li->data = NULL;
    return li;
}

void list_append(list* a_list, void* data, size_t data_size) {
    

    while(a_list->items!= NULL){
        
    }
}
