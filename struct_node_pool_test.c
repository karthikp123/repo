#include <stdio.h>
#include "struct_node_pool_test.h"

Rectangle rpool_nodes[RPOOL_SIZE];
Rectangle *rpool;

void clear_node (Rectangle * node)
{
   int index;
   
   node -> id = 0;
   
   
   for (index =0; index <= VTX_CNT-1; index++)
   {
       node -> vertex[index].x = 0;
       node -> vertex[index].y = 0;
   }

}

void *init_rpool (Rectangle **rpool_pptr)
{
    int index;
    
    for (index = 0; index < RPOOL_SIZE-1; index++)
    {
        clear_node (&rpool_nodes[index]);
        rpool_nodes[index].pool_index = index;
        rpool_nodes[index].next = &rpool_nodes[index+1];
         
    }
    rpool_nodes[index].next = NULL;
    //rpool = &rpool_nodes[0];
    *rpool_pptr = &rpool_nodes[0];
}

void dislay_rpool (Rectangle * rpool)
{
    int index, count;
    count = 0;
    while (rpool != NULL)
    {
        count++;
        rpool = rpool -> next;
    }
    
    printf ("count of rpool_nodes: %d\n", count);
}


Rectangle *alloc_pool_node (Rectangle **rpool_pptr)
{
    Rectangle *node;
    node = *rpool_pptr;
    *rpool_pptr = node->next;
    node->next = NULL;
    
    return node;
}

void free_pool_node (Rectangle **rpool_pptr, Rectangle *node_ptr)
{
    node_ptr->next = *rpool_pptr;
    *rpool_pptr = node_ptr;
}

int main ()
{
    Rectangle * assigned_node;
    Rectangle *nodes[10];

    rpool = &rpool_nodes[0];
    
    
    
    init_rpool (&rpool);
    dislay_rpool (rpool);
    
    rpool->id = 10;
    
    //assigned_node = alloc_pool_node (&rpool);
    //printf("%d\n",assigned_node->id);
    
    int i;
    /*for (i=0; i < 10; i++)
    {
        assigned_node = alloc_pool_node (&rpool);
        printf ("index of the current allocated node: %d\n",assigned_node->pool_index );
    }*/
    
    for (i = 0;i <10; i++)
    {
        nodes[i] = alloc_pool_node (&rpool);
        printf ("Adrress match %x - %x\n", nodes[i], &rpool_nodes[nodes[i]->pool_index]);
        if(nodes[i] != &rpool_nodes[nodes[i]->pool_index])
        {
           printf("Address mismatch found %d", i);
        }
        
    }
    dislay_rpool (rpool);
    
    free_pool_node (&rpool, nodes[9]);
        
    dislay_rpool (rpool);
    
    

    return 0;
}



