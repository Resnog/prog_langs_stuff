#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct{
    int x;
    int y;
}point;

void print_point(point* p) {
    printf("The point's coordinates are:\n  X:%d\n  Y:%d\n", p->x, p->y);
}

int main() {

    ll* list = ll_new();
    
    int x = 0;
    int y = 0;
    point* p = malloc(sizeof(point));
    p->x = x;
    p->y = y;

    ll_append(list, p, sizeof(point));
    print_point(p);
    for(int i = 0; i < 7; i++) {
        x++;
        y++;
        p->x = x;
        p->y = y;
        printf("Point %d: X:%d Y:%d\n", i, p->x, p->y);
        ll_append(list, p, sizeof(point));
    }
    
    struct ll_data* a = ll_data_new();
    printf("The point size is %d\n", a->data_size);
    point somePoint = {5,5};
    ll_data_write(a, &somePoint, sizeof(point));
    print_point((point*) a->data);
    int item_number = 1;
    struct ll_data* item = list->head;
    while(item) {
        printf("Number is %d\n", item_number);
        print_point( (point*) item->data);
        item = item->next;
        item_number++;
    }

    ll_print(list);
    
    free(a);
    free(p);
    return 0x00;
}