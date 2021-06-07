#pragma once
#include <iostream>
#include "Cat.h"
#include "Dog.h"

class Node
{
protected:
	Pet *data_;
	Node* next_;
public:
	Node();
	~Node();
	Pet *getData();
	void setData(Pet *data);
	Node* getNext();
	void setNext(Node* next);
	static Node* getNewNode(std::istream& is);

};

