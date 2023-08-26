#include "q_dll.h"

Queue :: Queue()
{
	headPtr = NULL;
	tailPtr = NULL;
	count = 0;
	
}

int Queue:: enqueue (char * msgBuffer, int size)
{
	Node * ptr;
	ptr = (Node *)malloc (sizeof(Node) + size);
	if (!ptr)
	{
		return 0;
	}
	
	ptr->size = size;
	memcpy (ptr->data, msgBuffer, size);
	
		
	if(headPtr == NULL)
	{
		headPtr = ptr;
		tailPtr = ptr;
		
		
	}
	else
	{
		ptr->next = headPtr;
		headPtr->prev = ptr;
		headPtr = ptr;
		
		
	}
	
	count++;
	
	return 0;
}

int Queue :: dequeue(char * buffer, int &size)
{
	Node * ptr;
	
	if(headPtr == NULL)
	{
		printf("queue is empty\n");
		return -1;
	}
	else if (headPtr == tailPtr)
	{
		ptr = headPtr;
		headPtr = NULL;
		tailPtr = NULL;

	}
	else
	{
		ptr = tailPtr;
		tailPtr = tailPtr->prev;
		tailPtr->next = NULL;
	}
	
	ptr->next = NULL;
	ptr->prev = NULL;
	
	size = ptr->size;
	memcpy (buffer, ptr->data, size);
	
	free(ptr);
	
	return 0;
}

void Queue :: display ()
{
	Node * ptr;
	while (ptr)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
		
	}
}

int main ()
{
	Queue q1;
	char * msg1 = "karthik";
	char * msg2 = "sharan";
	char buffer[100];
	int size;
	
	q1.enqueue (msg1, sizeof(msg1));
	q1.enqueue (msg2, sizeof(msg2));
	
	q1.display();
	
	q1.dequeue(buffer, size);
	
	return 0;
}





