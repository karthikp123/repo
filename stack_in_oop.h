#ifndef _STACK_IN_OOP_H_
#define _STACK_IN_OOP_H_

#include <iostream>

using namespace std;

enum StackDataType
{
	stackDataTypeNone,
	stackDataTypeInt,
	stackDataTypeFloat,
	stackDataTypeString,
	stackDataTypeClassObj,
	stackDataTypeMemory,
	stackDataTypeMax
};

enum StackStatus
{
	StackStatusSuccess,
	StackStatusEmpty,
	StackStatusAllocFail,
	StackStatusNull,
	StackStatusNospace
};

class StackNode
{
	private:
		StackNode *next;
		StackDataType datatype;
		void *data;
		int size;
	
	public:
		StackNode();
		~StackNode();
		void setDataNext(StackNode *ptr);
		void setDataDatatype (StackDataType datatype);
		void setdataData (void * data);
		void setDataSize (int size);
		
		StackNode * getDataNext ();
		StackDataType getDataType ();
		void* getDataData ();
		int getDataSize ();
		
		string getDataTypeStr ();
		void display();
		void displayData();
		
		
		
};

class Stack
{
	public:
	StackNode *top;
	int NodeCount;
	
	
	Stack ();
	
	
	private:
		StackStatus addNode(StackNode * stack_node_ptr);
		StackNode * deleteNode();
	
	public:
		StackStatus push (int data);
		StackStatus push (string data);
		StackStatus pushMemory (int size);
	
	
	void display ();
	
	StackStatus pop (char * dataBuffer, StackDataType &type, int &size);
	
	
};


#endif //_STACK_IN_OOP_H_


