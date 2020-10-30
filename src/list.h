
#ifndef OS_LIST_H
#define OS_LIST_H

#include "shared.h"

typedef struct _so_node {
    struct _so_node * next;
    void * data;
} _so_node;

typedef struct so_list {
    _so_node * head;
    void (*free_data)(void *);
} so_list;

so_list * so_list_create();

void so_list_push(so_list * list, void * data);

void * so_list_pop(so_list * list);

bool so_list_delete_at(so_list * list, size_t index);

void so_list_free(so_list ** list);

#endif
