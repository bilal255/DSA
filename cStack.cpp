/* 
	LIFO or Last In First Out
	This is the basic Stack program
	The nextNode reference of the last node is always null to avoid GARBAGE ACCESS
*/
#include <iostream>
#include "cNode.cpp"
using namespace std;
//Definition of Stack
class Stack
{
	public:
		Node *top;				//declaration of pointer i.e. points to the top of stack
	public:
		Stack(){ top = NULL;}	//default constructor i.e. assign top to Null
		Stack(Node *&ref)		//parameterized constructor i.e. generating a single node stack
		{ 
			top = ref;
			top->next = NULL;
			ref = NULL;
		}
		bool is_empty()			//pre-conditions to check whether the stack is empty 
		{
			if(top){ return false;}
			else { return true;}
			
		}
		bool is_not_empty()		//Or not
		{
			if(top){ return true;}
			else { return false;}
			
		}
		Stack &push(Node *& ptr)	//push function to insert node at the top of stack
		{
			ptr->next = top;
			top = ptr;
			ptr = NULL;
			return *this;
		}
		Node *pop()					//pop function to extract node from top of stack
		{
			Node *p = top;
			top = top->next;
			p->next = NULL;
			return p;
		}
		void print_stack()			//prints the whole stack 
		{
			if(top){ cout << "Stack is empty!";}
			else
			{
				cout << "The elements from top to bottom are: ";
				Node *ptr;
				while(ptr)
				{
					ptr->print();
					cout <<  endl;
					ptr = ptr->next;
				}
			}
		}
		Stack(const Stack &src)			//The default copy constructor gives shallow copy so default constructor is redefined
		{
			this->top = src.top;	//Two tracing pointers "sptr(source pointer) , dptr(destination pointer)" are used for assistance
			if(src.top)
			{
				Node *sptr, *dptr;
				dptr = top = new Node(*src.top);
				sptr = src.top->next;
				while(sptr)
				{
					dptr->next = new Node(*sptr);
					sptr = sptr->next;
					dptr = dptr->next;
				}
			}
		}
		Stack &operator = (const Stack &robj) //Definition of assignment operator
		{
			if (this == &robj){ return *this;}
			if (true){ Stack temp; temp.top = this->top;}
			if (true)
			{ 
				Stack temp = robj;
				this->top = temp.top;
				temp.top = NULL;
			}
			return *this;
		}
		~Stack()					//Self defined destructor delete all the nodes from stack
		{
			Node *p = top;
			while(p)
			{
				p = p->next;
				delete top;
				top = p;
			}
		}
};
#pragma once
