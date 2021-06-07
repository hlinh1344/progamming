#pragma once
#include <iostream>
#include "Cat.h"
#include "Dog.h"

template <class T> 
class Node
{
protected:
	T data_;
	Node* next_;
public:
	Node();
	~Node();
	T getData();
	void setData(T data);
	Node* getNext();
	void setNext(Node* next);
	static Node* getNewNode(std::istream& is);

};

