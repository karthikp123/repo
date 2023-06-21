#ifndef _STRUCT_HEADER_
#define _STRUCT_HEADER_

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

#endif // _STRUCT_HEADER_
