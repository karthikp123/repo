#ifndef _STRUCT_HEADER_
#define _STRUCT_HEADER_

#include <stdio.h>
#include <stdlib.h>

#define VTX_CNT 4
#define DESC_SIZE 31
#define RPOOL_SIZE 512 

typedef struct Point_t
{
    int x;
    int y;

}Point;

typedef struct Rectangle_t
{
    Point vertex[VTX_CNT];
    char  desc[DESC_SIZE];
    int   id;
    int   pool_index;
    struct Rectangle_t *next;
    

}Rectangle;

extern void clear_node (Rectangle *);
extern void *init_rpool (Rectangle **);
extern void dislay_rpool (Rectangle *);
extern Rectangle *alloc_pool_node (Rectangle **);
extern void free_pool_node (Rectangle **, Rectangle *);
extern int struct_node_pool_test_main ();

#endif // _STRUCT_HEADER_
