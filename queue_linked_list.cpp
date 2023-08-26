#include "queue_linked_list.h"

Queue ::Queue()
{
	front = NULL;
	rear = NULL;
}

int Queue:: enqueues(char *msg, int size)
{
	Node *newnode = (Node *)malloc(sizeof(Node)+size);
	newnode->next = NULL;
	newnode->length = size;
	
	memcpy(newnode->data, msg, size);
	
	/*Node **lfront, **lrear;
	*lfront = front;
	*lrear = rear; */
	
	if(front == NULL && rear == NULL)
	{
		front = newnode;
		rear = newnode;
	}
	
	else
	{
		Node *nodeptr;
		nodeptr = rear;
		nodeptr->next = newnode;
		rear = newnode;
	}
	
	
	return 0;
}	

int Queue:: dequeues(char *msgBuffer, int *size)
{
	Node *nptr;
	
	if(front == NULL)
		return -1;
	
	nptr = front;	
	front = nptr->next;
	nptr->next = NULL;
	memcpy(msgBuffer, nptr->data, nptr->length);
	*size = nptr->length;
	cout<<msgBuffer<<endl;
	return 0;
	
}

void Queue :: display()
{
	Node *ptr = front;
	if(front == NULL)
		cout<<"empty"<<endl;
	else
	{
		while(ptr != NULL)
		{
			cout<<"data is:"<<ptr->data<<endl;
			ptr = ptr->next;
		}
	}	
}

int main()
{
	char ch = 'c', cs ='p', ce = 'p', t;
	Queue q1;
	if(q1.enqueues(&ch, sizeof(ch)) == 0)
		printf("done!!\n");
		
	if(q1.enqueues(&cs, sizeof(cs)) == 0)
		printf("done!!\n");
		
	if(q1.enqueues(&ce, sizeof(ce)) == 0)
		printf("done!!\n");
		
	q1.display();
	
	int sis;
	if(q1.dequeues(&t, &sis) == 0)
		printf("deleted!!\n");
		
	if(q1.dequeues(&t, &sis) == 0)
		printf("deleted!!\n");
		
	if(q1.dequeues(&t, &sis) == 0)
		printf("deleted!!\n");
	
	q1.display();
		
	return 0;
	
}
