#pragma once
#include <iostream>


class Node
{
protected:
	int data;
	Node* next;
public:
	Node();
	Node(int a_data);
	Node(int a_data, Node * a_next);
	~Node();
	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
};

