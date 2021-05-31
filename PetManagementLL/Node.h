#pragma once
#include <iostream>
#include "Cat.h"
#include "Dog.h"

class Node
{
protected:
	Pet *data_;
	Node* pNext_;
public:
	Node();
	~Node();
	Pet *getData();
	void setData(Pet *data);
	Node* getpNext();
	void setpNext(Node* pNext);
	static Node* getNewNode(std::istream& is);

};

