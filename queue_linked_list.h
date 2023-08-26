#ifndef queue_test_h
#define queue_test_h

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

class Node {

	public:	
	Node *next;
	int length;
	char data[0];
};

class Queue {
	
	Node *front;
	Node *rear;
	
	public:
		Queue();
		int enqueues(char *msg, int size);
		int dequeues(char *msgBuffer, int *size);
		int getQueueSize();
		void display();
};

#endif
