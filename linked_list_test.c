#include "linked_list_test.h"

extern "C"
{

LLNODE *lhead = NULL;

int addListNode (LLNODE ** headPPtr, LLNODE * addNode)
{
	
	LLNODE ** nextPPtr;
	LLNODE *newNode;
	LLNODE * nodePtr;
	
	if(!headPPtr || !addNode)
	{
		return -1;
	}
	
	nextPPtr = headPPtr;
	nodePtr = *headPPtr;
	
	newNode = (LLNODE *) malloc (sizeof (LLNODE));
	if(newNode == NULL)
	{
		return -2;
	}
	
	memcpy (newNode, addNode, sizeof (LLNODE));
	
	/*if (*headPPtr == NULL)
	{
		*headPPtr = newNode;
		return 0;
	}*/
	
	while (nodePtr)
	{
		if (nodePtr->data > addNode->data)
		{
			
			break;
			
			/*newNode->next = *nextPPtr;
			*nextPPtr = newNode; */
			
			return 0;
		}
		nextPPtr = &(nodePtr->next);
		nodePtr = nodePtr->next; 
	}
	
	newNode->next = *nextPPtr;
	*nextPPtr = newNode; 
	
	/**nextPPtr = newNode;*/
	
	
	return 0;
	
}

int addFirst (LLNODE **headPPtr, LLNODE * addNode)
{
	if (addNode == NULL)
	{
		return -1;
	}
	
	
	LLNODE * newNode;
	LLNODE * nodePtr;
	LLNODE **nextPPtr;
	
	newNode = (LLNODE *) malloc (sizeof(LLNODE));
	memcpy (newNode, addNode, sizeof(LLNODE));
	
	nextPPtr = headPPtr;
	nodePtr = *headPPtr;
	
	
	if(*headPPtr != NULL)
	{
		newNode->next = *nextPPtr;
		*nextPPtr = newNode; 
		
		return 0;
	}
	*nextPPtr = newNode;
	
	return 0;
}

int addLast (LLNODE ** headPPtr, LLNODE * addNode)
{
	LLNODE * ptr;
	LLNODE *newNode;
	
	newNode = (LLNODE *) malloc (sizeof(LLNODE));
	memcpy (newNode, addNode, sizeof(LLNODE));
	
	if (*headPPtr == NULL)
	{
		*headPPtr = newNode;
	}
	
	ptr = *headPPtr;
	
	while(ptr->next != NULL)
	{
		ptr= ptr->next;
	}
	
	ptr->next = newNode;
	newNode->next = NULL;
	
	return 0;
	
	
}

int delete_Last (LLNODE **headPPtr, LLNODE *delNode)
{
	LLNODE * ptr;
	LLNODE * node;
	
	if (*headPPtr == NULL)
	{
		return -1;
	}
	
	ptr = *headPPtr;
	
	while(ptr->next->next != NULL)
	{
		ptr= ptr->next;
	}
	node = ptr->next;
	
	memcpy(delNode, node, sizeof(LLNODE));
	
	ptr->next = NULL;
	free (ptr);
	
	return 0;
}

int add_node(int data)
{
	LLNODE node;
	node.data = data;
	node.next = NULL;
	int status = addListNode (&lhead, &node);
	
	return 0;
	
	
}



int deleteListNode (LLNODE ** headPPtr, int key)
{
	LLNODE ** nextPPtr;
	LLNODE *nodePtr;
	
	int data;
	
	nextPPtr = headPPtr;
	nodePtr = *headPPtr;
	
	while (nodePtr)
	{
		if(nodePtr->data == key)
		{
			data = nodePtr->data;
			*nextPPtr = (nodePtr->next);
			//free(nodePtr);
			
			return data;
		}
		
		nextPPtr = &nodePtr -> next;
		nodePtr = nodePtr -> next;
	}
	
	return -1;
}



int deleteFirst (LLNODE ** headPPtr, LLNODE * delNode)
{
	LLNODE ** nextPPtr;
	LLNODE * nodePtr;
	
	nodePtr = *headPPtr;
	nextPPtr = headPPtr;
	
	LLNODE * ptr;
	ptr = (LLNODE *) malloc (sizeof(LLNODE));
	
	int data;
	
	if(*headPPtr != NULL)
	{
		*nextPPtr = nodePtr->next;
		memcpy (delNode, nodePtr, sizeof(LLNODE));
		free(nodePtr);
		
		return 0;
	}
	
	printf ("list is empty!\n");
	memset (delNode, 0, sizeof(LLNODE));
	return 0;
	
}


int deleteLast (LLNODE ** headPPtr, LLNODE *delNode)
{
	LLNODE **nextPPtr;
	LLNODE * nodePtr;

	if(!headPPtr || !delNode)
	{
		return -3;
	}
	
	nextPPtr = headPPtr;
	nodePtr = *headPPtr;
	
	while (nodePtr)
	{
		if (nodePtr->next == NULL)
		{
			break;
		}
		
		nextPPtr = &(nodePtr->next);
		nodePtr = nodePtr->next;
	}
	
	
	*nextPPtr = NULL;
	
	memcpy (delNode, nodePtr, sizeof(LLNODE));
	
	free(nodePtr);
	
	return 0;
	
	
}


/*
int delete_node (LLNODE **head_pptr, int key)
{
	if (head_pptr == NULL)
	{
		printf ("empty list");
		return -1;
	}	
	
	LLNODE * cur_node, prev_node, node;
	int data;
	prev_node = NULL;
	cur_node = *head_pptr;
	
	
	while (cur_node->data != key  && cur_node -> next != NULL)
	{
		prev_node = cur_node;
		cur_node = cur_node->next;
	}
	
	node = cur_node;
	
	if (prev_node == NULL )
	{
		*head_pptr = node->next;
	}
	else if (cur_node->next == NULL)
	{
		prev_node->next = NULL;
	}
	else
	{
		prev_node->next = node->next;
	}
	
	data = node-> data;
	free(node);
	
	return data;
	
}*/

void display ()
{
	LLNODE * ptr;
	ptr = lhead;
	//printf ("helo\n");
	while (ptr != NULL)
	{
		//printf ("helo");
		printf ("%d\n",ptr->data);
		ptr = ptr->next;
	}
}



int linked_list_main ()
{
	int status;
	LLNODE node1, node2, node3, node4, node5,delNode;
	node1.data = 8;
	node1.next = NULL;
	node2.data = 10;
	node2.next = NULL;
	node3.data = 9;
	node3.next = NULL;
	node4.data = 12;
	node4.next = NULL;
	node5.data = 6;
	node5.next = NULL;

	status = addListNode (&lhead, &node1);
	status = addListNode (&lhead, &node2);
	status = addListNode (&lhead, &node3);
	status = addListNode (&lhead, &node4);
	status = addFirst (&lhead, &node5);
	//status = add_node (20);
	//status = add_node (10);
	display();
	printf ("\n");
	
	deleteLast (&lhead,&delNode);
	//deleteListNode (&lhead, 10);
	display();
	printf ("\n");
	
	status = addListNode (&lhead, &node5);
	display();
	return 0;
}

#ifndef RELOCATABLE_OBJ
int main ()
{
	linked_list_main ();
}
#endif //RELOCATABLE_OBJ

}

