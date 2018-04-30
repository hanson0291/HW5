//---------------------------------------------------------------------
// Name: Andrew Hanson
// Email: awh5563@psu.edu
// Class: CMPSC 122, Section 3
// Program 4.1
//
// Description: Contains List and Stack implementations from
// class notes.
//
//------


#ifndef STACK_H
#define STACK_H

#include "list.h"

class Stack
{
private:
	List* list;
public:
	Stack() { list = new List(); }
	~Stack() { delete list;	}

	bool isEmpty() { return list->isEmpty(); }
	void clear() { list->clear(); }
	void push(int data) { list->addToHead(data); }
	int pop() { return list->removeHead(); }
	int top() { return list->valueOf(list->getHead()); }
};

#endif
