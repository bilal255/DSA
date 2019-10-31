/* 
	FIFO or First In First Out
	This is basic Que class inherited from Stack
*/
#include <iostream>
#include "cStack.cpp"
using namespace std;
//Definition of Queue
class Que : protected Stack
{
	Node *tail;
public:
	Que () : tail(NULL) {}
	Que(Stack *& ref) : Stack(*ref), tail(top) {}
	//Copy Constructor
	Que(const Que &src)
	{
		this->top = src.top;
		this->tail = src.tail;
		if(src.top)
		{
			Node *sptr, *dptr;
			dptr = this->top = new Node(*src.top);
			sptr = top->next;
			while(sptr)
			{
				dptr->next = new Node(*sptr);
				sptr = sptr->next;
				dptr = dptr->next;
			}
			tail = dptr;
		}
	}
	bool is_empty(){ Stack :: is_empty();}   //Pre-conditions
	Node *remove() { return Stack :: pop();} //Remove function works same as pop()
	
	Que &add(Node *& ptr)			//Add node element at last of the queue
	{
		if(tail)
		{
			tail->next = ptr;
			tail = tail->next;
			
		}
		else
		{
			top = tail = ptr;
		}
		tail->next = NULL;
		ptr = NULL;
		return *this;
	}
	void print_que() { Stack :: print_stack();} //Prints queue from top to bottom
	//Definition of assignment operator
	Que &operator = (const Que &robj)
	{
		if(this == &robj){ return *this;}
		if(true) { Que temp; temp.top = top; temp.tail = tail;}
		if(true) { Que temp = robj; top = temp.top; temp.top = NULL;}
		return *this;
	}
	
	/*
	Destructor of stack class is called implicitly and work fine
	No need to redefine the destructor
	*/
};
