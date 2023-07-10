#include "stack_in_oop.h"

/*------------------------- StackNode Class functions ---------------------*/


StackNode :: StackNode()
{
	next = NULL;
	datatype = stackDataTypeNone;
	data = NULL;
	size = 0;
}

StackNode :: ~StackNode()
{
	
	if(data)
		free(data);
		data = NULL;
	next = NULL;
	size = 0;
	datatype = stackDataTypeNone;
	cout << "destructor is called"<< endl<<endl;
}


void StackNode::setDataNext(StackNode *ptr)
{
	this->next = ptr;	
	
}

void StackNode::setDataDatatype (StackDataType datatype)
{
	this->datatype = datatype;
}

void StackNode::setdataData (void * data)
{
    
	this->data = data;
}

void StackNode::setDataSize (int size)
{
	this->size = size;
}

StackNode * StackNode :: getDataNext ()
{
	return this->next;
}

StackDataType StackNode :: getDataType ()
{
	return this->datatype;
	
}

string StackNode :: getDataTypeStr ()
{
	switch (this->datatype)
	{
		case stackDataTypeNone:
			return "None";
			
		case stackDataTypeInt:
			return "Integer";
			
		case stackDataTypeFloat:
			return "Float";
			
		case stackDataTypeString:
			return "String";
		case stackDataTypeClassObj:
			return "class Object";
		case stackDataTypeMemory:
			return "None";
		default :
			return "Nothing";
	}
}

void * StackNode :: getDataData ()
{
	return this->data;
}

int StackNode :: getDataSize ()
{
	return this->size;
}


void StackNode::displayData()
{
	cout <<"data at: " <<data << endl;
	if(!data)
	{
		return;
	}
	switch(datatype)
	{
		case stackDataTypeInt:
			cout << "data: " << *((int *)(data)) <<endl;
			break;
		case stackDataTypeString:
			cout << "data: " << *((string *)(data)) <<endl;
			break;
		case stackDataTypeFloat:
			cout << "data: " << *((float *)(data)) <<endl;
			break;
		case stackDataTypeMemory:
			cout << "data: None"<<endl;
			break;
	}
}

void StackNode :: display ()
{
	cout << "datatype: " << getDataTypeStr() << endl;
	cout << "size: " << size << endl;
	displayData();
	cout << "next: " << next << endl;
	
}



/*------------------------- Stack Class functions ---------------------*/



Stack::Stack ()
{
	top = NULL;
	NodeCount = 0;
}

StackStatus Stack::addNode(StackNode * stacknode_ptr)
{
	if (!stacknode_ptr)
	{
		cout << "Invalid Pointer"<<endl;
		return StackStatusNull;
	}	
	
	if(!top)
	{
		top = stacknode_ptr;
		
	}
	else
	{
		stacknode_ptr->setDataNext(top);
		top = stacknode_ptr;
	}
	
	NodeCount++;
	
	return StackStatusSuccess;
}




StackStatus Stack::push (int data)
{
		
	StackNode *node = new StackNode;
	
	node->setDataDatatype(stackDataTypeInt);	
	int * ptr = (int *) malloc (sizeof(int));
	*ptr = data;
	node->setdataData ((void *)(ptr));
	node->setDataSize (sizeof(int));
	
	StackStatus status = addNode (node);
	
	cout << "pushed successfully"<< endl;
	
	return status;
}

StackStatus Stack::push (string data)
{
	StackNode *node = new StackNode;
	
	node->setDataDatatype(stackDataTypeString);
	string * ptr = (string *) malloc (sizeof(string));
	*ptr = data;
	node->setdataData((void *)(ptr));
	node->setDataSize(sizeof(string));
	
	StackStatus status = addNode(node);
	
	cout << "pushed successfully"<< endl;
	
	return status;
}

StackStatus Stack::pushMemory (int size)
{
	StackNode *node = new StackNode;
	
	node->setDataDatatype(stackDataTypeMemory);
	void * ptr = (void *) malloc (size);
	node->setdataData(ptr);
	node->setDataSize(size);
	
	StackStatus status = addNode(node);
	
	cout << "pushed successfully"<< endl;
	
	return status;
}



StackNode * Stack:: deleteNode()
{
	StackNode *poped;
	if(!top)
	{
		return NULL;
	}
	else
	{
		
		poped = top;
		top = top->getDataNext();
	}
	return poped;
}

StackStatus Stack:: pop (char * dataBuffer, StackDataType &type, int &size)
{
	if(NodeCount == 0)
	{
		cout << "Stack is empty! Can't Pop"<<endl;
		return StackStatusEmpty;
	}
	
	StackNode *poped;
	poped = deleteNode ();
	
	if (!poped)
	{
		type = stackDataTypeNone;
		size = 0;
		
		return StackStatusEmpty;
	}
	if (poped->getDataSize ()>size)
	{
		return StackStatusNospace;
	}
	
	//type = poped->getDataType();
	//size = poped->getDataSize();
	
	
	//cout << "poped item datatype:" << type << endl <<"size: "<< size << endl;
	//cout << "one poped"<<endl<<endl;
	NodeCount--;
	delete poped;
	
	return StackStatusSuccess;
	
}

void Stack::display ()
{
	
	StackNode * ptr = top;
	int i = 1;
	
	if (top == NULL)
	{
		cout << "Stack is Empty! Nothing to display" << endl;
	}
	
	while (ptr != NULL)
	{
		cout << "Node No. "<< i<<endl;
		ptr->display();
		ptr = ptr->getDataNext();
		cout << endl;
		i++;
	}
}

int main ()
{
	
	char popedData[100];
	int size;
	StackDataType type;
	
	Stack stack;
	stack.push(20);
	stack.push("karthi");
	stack.push("snajay");
	stack.push("varun");
	stack.push("sumith");
	stack.push(30);
	stack.push(40);
	stack.pushMemory(10);
	
	
	stack.display();
	
	StackStatus status;
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	status = stack.pop(popedData, type, size);
	
	
	//stack.push("adithya");
	stack.push(50);
	//stack.push("karthi");
	
	//stack.display();
	
	
	//stack.pushMemory(10);
	
	//status = stack.pop(popedData, type, size);
	//status = stack.pop(popedData, type, size);
	
	stack.display();
	
	
	return 0;
}

