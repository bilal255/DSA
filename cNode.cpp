//self referential node class i.e. stack elements
#include <iostream>
using namespace std;
//definition of Node Class
class Node
{
		int n;						//keep track of no. of nodes added
		int data;					//data carrier
	public:
		Node *next;
		Node *priority;					//pointer to refer the next node
	Node(){ this->priority = 0; this->n = 0;this->data = -1; next = NULL;} //default class constructor
	
	Node(int d, int num){ this->data = d; this->n = num;}			//parameterized constructor
	
	void set_data(int v, int v1){ this->data = v; this->n = v1;} //setter function
	
	int get_data(){ return data;}   //getter function
	int get_n() { return n;}
	void print(){ cout << data;}	//prints data
		
};
#pragma once
