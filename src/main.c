#include <string.h>
#include "shared.h"
#include "list.h"

typedef struct _so_host_info {
    char * name;
    int id;
} so_host_info;

so_host_info * so_host_create(const char * name, int id);
void so_host_info_free(so_host_info * hi);

int main()
{

    /*  1ra parte */
    so_list * list = so_list_create();

    so_host_info * pc1 = so_host_create("ola k ase1", 0);
    so_host_info * pc2 = so_host_create("ola k ase2", 1);
    so_host_info * pc3 = so_host_create("ola k ase3", 2);

    so_list_push(list, pc1);
    so_list_push(list, pc2);
    so_list_push(list, pc3);

    so_list_free(&list);

    /*  2da parte */
    list = so_list_create();

    pc1 = so_host_create("ola k ase1", 0);
    pc2 = so_host_create("ola k ase2", 1);
    pc3 = so_host_create("ola k ase3", 2);

    so_list_push(list, pc1);
    so_list_push(list, pc2);
    so_list_push(list, pc3);

    so_host_info_free((so_host_info *)so_list_pop(list));
    so_host_info_free((so_host_info *)so_list_pop(list));
    so_host_info_free((so_host_info *)so_list_pop(list));

    so_list_free(&list);

    /*  3da parte */
    list = so_list_create();
    list->free_data = (void (*)(void *)) so_host_info_free;

    pc1 = so_host_create("ola k ase1", 0);
    pc2 = so_host_create("ola k ase2", 1);
    pc3 = so_host_create("ola k ase3", 2);

    so_list_push(list, pc1);
    so_list_push(list, pc2);
    so_list_push(list, pc3);

    so_list_delete_at(list, 2);
    so_list_delete_at(list, 1);
    so_list_delete_at(list, 0);
    
    so_list_free(&list);

    return 0;
}

so_host_info * so_host_create(const char * name, int id)
{
    so_host_info * retval;
    so_calloc(retval, 1, sizeof(so_host_info));
    retval->name = strdup(name);
    retval->id = id;
}

void so_host_info_free(so_host_info * hi)
{
    free(hi->name);
    free(hi);
}