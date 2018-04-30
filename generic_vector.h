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


#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <iostream>
#include <type_traits>
#include <stdlib.h>

template <class T>
class GenericVector
{
private:
	int vector_size;
	int vector_capacity;
	T* data;

	void resize();

public:
	GenericVector();
	GenericVector(int);
	~GenericVector();

	T& at(int);
	T& operator[](int);
	T& front() { return data[0]; }
	T& back() { return data[vector_size - 1]; }

	void push_back(T);
	void insert(int, T);
	void pop_back();

	int size() { return vector_size; }
	int capacity() { return vector_capacity; }

	void print();
};

template <class T>
GenericVector<T>::GenericVector()
{
	vector_size = 16;
	data = new T[vector_size];
}

template <class T>
GenericVector<T>::GenericVector(int capacity)
{
	vector_size = 0;

	if (capacity < 16)
	{
		vector_capacity = 16;
		data = new T[16];
	}
	else
	{
		int c = 16;
		
		while (c <= capacity)
			c *= 2;
		
		vector_capacity = c;
		data = new T[c];
	}
}

template <class T>
GenericVector<T>::~GenericVector()
{
	while (vector_size > 0)
		pop_back();

	delete [] data;
}

template <class T>
void GenericVector<T>::resize()
{
	T* temp = data;
	data = new T[vector_capacity *= 2];

	for (int i = 0; i < vector_size; ++i)
		data[i] = temp[i];

	delete [] temp;
}

template <class T>
T& GenericVector<T>::at(int index)
{
	if (0 <= index && index < vector_size)
		return data[index];
	
	std::cout << "Invalid index accessed" << std::endl;
	exit(1);
}

template <class T>
T& GenericVector<T>::operator[](int index)
{
	if (0 <= index && index < vector_size)
		return data[index];
	
	std::cout << "Invalid index accessed" << std::endl;
	exit(1);
}

template <class T>
void GenericVector<T>::push_back(T value)
{
	if (vector_size == vector_capacity)
		resize();

	data[vector_size++] = value;
}

template <class T>
void GenericVector<T>::insert(int index, T value)
{
	if (0 <= index && index < vector_size)
	{
		if (vector_size == vector_capacity)
			resize();
		
		for (int i = vector_size; i > index; --i)
			data[i] = data[i-1];
		
		++vector_size;
		data[index] = value;
	}
}

template <class T>
void GenericVector<T>::pop_back()
{

	if (vector_size > 0)
	{
		if (std::is_pointer<T>::value)
			delete data[--vector_size];
		else
			data[--vector_size] = T();
	}
}

template <class T>
void GenericVector<T>::print()
{
	std::cout << "elements(" << vector_size << "):";
	for (int i = 0; i < vector_size; ++i)
		std::cout << " " << data[i];
	std::cout << std::endl;
}

#endif
