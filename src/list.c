#include "list.h"

so_list * so_list_create()
{
    so_list * retval;
    so_calloc(retval, 1, sizeof(so_list));
    return retval;
}

void so_list_push(so_list * list, void * data)
{
    _so_node * new_head;

    if (!list) {
        return;
    }

    so_calloc(new_head, 1, sizeof(_so_node));
    new_head->data = data;
    new_head->next = list->head;

    list->head = new_head;
}

void * so_list_pop(so_list * list)
{
    void * retval = NULL;
    _so_node * top_node;

    if (!list || !list->head) {
        return retval;
    }

    top_node = list->head;
    list->head = top_node->next;
    free(top_node);

    retval = top_node->data;

    return retval;
}

bool so_list_delete_at(so_list * list, size_t index)
{
    _so_node * current;
    _so_node * next;
    size_t i;

    if (!list || !list->head) {
        return false;
    }

    current = list->head;

    i = 0;
    while (next = current->next, next && i < index) {
        current = next;
        i++;
    }

    if (i != index) {
        return false;
    } else if (i == 0) {
        list->head = next;
    }

    free(current);

    return true;
}

void so_list_free(so_list ** list)
{

    _so_node * current;
    _so_node * next;
    size_t i;

    if (!*list) {
        return;
    }

    current = (*list)->head;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current->next);

    *list = NULL;
}
