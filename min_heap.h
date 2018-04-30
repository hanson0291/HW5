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


#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "generic_vector.h"
#include <cstdlib>

// Heap implementation derived from: 
// https://www.geeksforgeeks.org/binary-heap/

class MinHeap
{
private:
	// Creating internal "nested" classes is an alternative
	// to friending entire classes. This way, only MinHeap has access
	// to the a HeapNode object and its contents. 
	class HeapNode
	{
	public:
		int priority;
		int value;
		HeapNode()  { value = priority = 0; }
		HeapNode(int v, int p) { value = v; priority = p; }
		~HeapNode() { value = priority = 0; }

	};

	GenericVector<HeapNode*>* heap;

	int size() { return heap->size(); }
	void swap_heap_node(int, int);
	void min_heapify(int);



public:
	MinHeap() { heap = new GenericVector<HeapNode*>(); }
	~MinHeap() { delete heap; }

	bool is_empty() { return size() == 0; }

	int parent(int index) { return index / 2; }
	int left(int index) { return index * 2; }
	int right(int index) { return index * 2 + 1; }

	int min() { return (*heap)[1]->value; }
	int extract_min();

	void add_with_priority(int v, int priority);

	void insert(int, int);
	void decrease_priority(int, int);
};

void MinHeap::swap_heap_node(int x, int y)
{
	HeapNode* temp = (*heap)[x];
	(*heap)[x] = (*heap)[y];
	(*heap)[y] = temp;
}

void MinHeap::min_heapify(int index)
{
	int lc = left(index);
	int rc = right(index);

	int smallest = index;

	// do comparisons with child nodes to determine small value
	// if l or r is > size, then there is no node at that index
	if (lc <= size() && (*heap)[lc]->priority < (*heap)[index]->priority)
		smallest = lc;
	if (rc <= size() && (*heap)[rc]->priority < (*heap)[index]->priority)
		smallest = rc;
	if (smallest != index) // if the node at index is not the smallest, perculate down the heap
	{
		swap_heap_node(index, smallest);
		min_heapify(smallest); // check again if we need to perculate down another level
	}
}

int MinHeap::extract_min()
{
	int min_value;

	if (is_empty())
		exit(1);

	if (size() == 1) 
	{
		min_value = (*heap)[1]->value;
		heap->pop_back();
		return min_value;
	}

	// THE FOLLOWING LINE IS CAUSING A SEG FAULT~!
	min_value = (*heap)[1]->value; // copy min value before delete the top node

	swap_heap_node(1, size()); // swap min node with last node
	delete (*heap)[size()]; // delete last node (prev min node)

	min_heapify(1); // reheapify starting at root node (index 1)	

	return min_value;
}

void MinHeap::insert(int value, int priority)
{
std::cout << "priority = " << priority << std::endl;
std::cout << "value = " << value << std::endl;

	heap->push_back(new HeapNode(value, priority));

	int index = size();

std::cout << "index = " << index << std::endl;

	// position new node correctly in min heap
	// THIS LINE IS CAUSING PROBLEMS
	while ( index != 1 && (*heap)[parent(index)]->priority > (*heap)[index]->priority) {
	//while(index != 1){
std::cout << "\n\n no crash yet 2 \n\n";

		// since the new node is smaller than its parent,
		// we the nodes to swap places. 
		swap_heap_node(index, parent(index));
		index = parent(index);
		// update the index to reflect our new position in the heap
	} 
}

void MinHeap::decrease_priority(int index, int priority) {	
	(*heap)[index]->priority = priority;

	while ( index != 1 && (*heap)[parent(index)]->priority > (*heap)[index]->priority) {
		swap_heap_node(index, parent(index));
		index = parent(index);
	}
}

void MinHeap::add_with_priority(int v, int priority){
	(*heap)[v]->priority = priority;

	while ( v != 1 && (*heap)[parent(v)]->priority > (*heap)[v]->priority) {
		swap_heap_node(v, parent(v));
		v = parent(v);
	}
}


#endif
