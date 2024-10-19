#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

ll* ll_new(void){

    ll* list = (ll*) malloc(sizeof(ll));
    list->head = NULL;
    list->tail= NULL;

    return list; 
}

struct ll_data* ll_data_new(void){
    struct ll_data* data_node =  (struct ll_data*) malloc(sizeof(struct ll_data));

    data_node->data = NULL;
    data_node->data_size = 0;
    data_node->next = NULL;
    data_node->prev= NULL;

    return data_node;
}

void ll_data_write(struct ll_data* data_node, void* data, size_t data_size){
    data_node->data_size = data_size;
    data_node->data = malloc(data_size);
    if(!data_node->data) {
        fprintf(stderr, "Failed to allocate memory for data node\n");
        free(data_node->data);
        exit(1);
    }
    memcpy(data_node->data,
           data,
           data_node->data_size);
}

void ll_append(ll* list, void* data, size_t data_size) {
    

    // Write data to new list item and point to the tail of the list
    struct ll_data* new_ll_data = ll_data_new();
    ll_data_write(new_ll_data, data, data_size);

    // If there is no head then attach node to head and tail 
    if(!list->head) {
        list->head = new_ll_data;
    }else{
        if(!list->tail){
            new_ll_data->prev = list->head;
            list->tail =  new_ll_data; 
            list->head->next = list->tail;
        }else{
        // Make prev item the prev tail item
        new_ll_data->prev = list->tail;
        list->tail->next = new_ll_data;
        // Add as the new tail of the list now
        list->tail =  new_ll_data; 
        }
    }

    // Add to the current size of the list
    list->size++;
}

