#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
#define LIST_H

typedef struct{
    size_t data_size;
    void* data;
}list_item;

typedef struct {
    list_item** items;
    size_t size;
}list;


list* list_new(void);

list_item* lit_new_list_item(void);

void list_append(list* head, void* data, size_t data_size);

#endif //  LIST_H
