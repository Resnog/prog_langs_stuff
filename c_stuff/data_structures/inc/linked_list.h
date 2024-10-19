#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//#include "data.h"

/*!
 *  Linked List Item.
 *  
 *  Double linked list item that points to the previous
 *  and the next object in the list. It has a variable 
 *  type object.
*/
struct ll_data{
    size_t data_size;
    struct ll_data* prev;
    struct ll_data* next;
    void* data;
};

/*!
 *  Linked List.
 *  
 *  A double linked list of a variable object size
 * */
typedef struct {
    struct ll_data* head;
    struct ll_data* tail;
    size_t size;
}ll;

ll* ll_new(void);

// Linked list class methods

// Create a new linked list data object
struct ll_data* ll_data_new(void);

// Append data to the tail of the linked list
void ll_append(ll* list, void* data, size_t data_size);

// Pop the head of the linked list
void ll_pop(ll* list);

// Pop the tail of the linked list
void ll_pop_tail(ll* list);

// Return a pointer to the item at the index
void ll_get_item(ll* list, int index);

// Linked list data class methods
void ll_data_write(struct ll_data* data_node, void* data, size_t data_size);



#endif //  LINKED_LIST_H
