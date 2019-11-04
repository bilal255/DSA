#include <iostream>
#include <fstream>
#include "cNode.cpp"
//#include "l_list.h"
using namespace std;

//Definition of link list class
class l_list
{
protected:
	cNode* head;
	int count;
public:
	l_list() : head(NULL), count(0){}
	l_list(cNode*& ptr) : head(ptr), count(1)
	{
		head->NN = ptr = NULL;
	}
	bool is_empty() {
		if (head) { return false; }else { return true; }
	}
	bool is_not_empty() {
		if (head) { return true; }
		else { return false; }
	}
	int get_count()
	{
		return count;
	}
	//Insert Node
	l_list& insert(cNode*& p)
	{
		p->NN = head;
		head = p;
		++count;
		p = NULL;
		return *this;
	}
	//Insert at any index
	l_list& insert_at(int index, cNode*& ptr)
	{
		if (index <= 0)
		{
			return insert(ptr);
		}
		if (index > count)
		{
			index = count;
		}
		cNode* rptr = head;
		for (int i = 1; i < index; ++i)
		{
			rptr = rptr->NN;
			ptr->NN = rptr->NN;
			rptr->NN = ptr;
			++count;
			ptr = NULL;
			return *this;
		}
		
	}
	//Remove node 
	cNode* remove() 
	{
		cNode* ref = head;
		head = head->NN;
		ref->NN = NULL;
		--count;
		return ref;
	}
	//For removing node at any index
	cNode* remove_at(int index)
	{
		if (index <= 0) { return remove(); }
		if (index >= count) { index = count - 1; }
		cNode* ptr = 0, * rptr = head;
		for (int i = 1; i < index; ++i)
		{
			rptr = rptr->NN;
		}
		ptr = ptr->NN;
		rptr->NN = ptr->NN;
		ptr->NN = NULL;
		--count;
		return ptr;
	}
	//Insert Nodes
	l_list & insert (cNode *& ptr)
	{
		ptr->next = head;
		head = ptr;
		ptr = NULL;
		count++;
		return *this;
	}
	
	//File Handling
	l_list(ifstream& iFile) : head(NULL), count(0)
	{
		if (!iFile.is_open())
		{
			cerr << "\n l_list :: constructor : File not open!";
			exit(1);
		}
		iFile.read((char*)& count, sizeof(count));
		if (count > 0)
		{
			cNode* p;
			p = head = new cNode(iFile);
			for (int i = 1; i < count; ++i)
			{
				p->NN = new cNode(iFile);
				p = p->NN;
			}
			p->NN = NULL;
		}
	}
};
#pragma once