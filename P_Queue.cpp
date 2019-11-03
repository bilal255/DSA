/*  
	Type of Que i.e gives priority to the node element having larger data value
*/
#include <iostream>
#include "cQueue.cpp"
using namespace std;
//definition of Priority Queue
class p_que : public Que
{
	
public:
	p_que(){}				//default constructor
	p_que(Node *& ref){}	//parameterized constructor
	
	p_que &add(Node *& ptr) //Add function to add node in queue class according to its priority
	{
		if(!top){ Que :: add(ptr); return *this;} //to add first element in que irrespective of priority
		else if(tail->priority >= ptr->priority)  //to add element at the end of queue
		{ 
			Que :: add(ptr); return *this;  
		}
		else if(top->priority < ptr->priority)    //to add element at start of the queue
		{
			Stack :: push(ptr); return *this;
		}
		else
		{
			Node *bptr, *rptr;						//bptr(back pointer) keep track of rptr(runner pointer)
			bptr = rptr = top;
			while (ptr->priority <= rptr->priority) //to insert element according to its priority in queue
			{
				bptr = rptr;
				rptr = rptr->next;
				ptr->next = rptr;
				bptr->next = ptr;
				ptr = NULL;
				++n;
			}
			return *this;
		}
	}	
	p_que (const p_que &src) : Que((Que&) src){}    //Copy constructor same as Queue class
	
	p_que & operator = (const p_que &robj)		   //Assignment operator
	{
		if(this == &robj){ return * this;}
		((Que) *this)->operator = ((Que&) robj);
		return *this;
	}
};
#pragma once