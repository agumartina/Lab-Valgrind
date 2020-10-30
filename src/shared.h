#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

#define so_calloc(x, y, z)                                                                                             \
    {                                                                                                                  \
        (x = (typeof(x)) calloc(y, z)) ? (void) 1 : printf("error alloc memory");                                      \
    }
