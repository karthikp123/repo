#ifndef _LINKED_LIST_TEST_H_
#define _LINKED_LIST_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUSSUCCESS 0
#define STATUSHEAPFAIL 1
#define STATUSNULLPTR 2

typedef struct node_t
{
	int data;
	struct node_t * next;
	
}LLNODE;

#endif //_LINKED_LIST_TEST_H_
