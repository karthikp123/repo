#ifndef _Q_DLL_H_
#define _Q_DLL_H_

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct Node_t
{
	struct Node_t *prev;
	struct Node_t *next;
	int size;
	char data[0];
}Node;

class Queue
{
	private:
		Node * headPtr;
		Node * tailPtr;
		int count;
	
	public:
		Queue();
		//~Queue();
		int enqueue(char * msgBuffer, int size);
		int dequeue(char * buffer, int &size);
		void display ();
};


#endif //_Q_DLL_H_
