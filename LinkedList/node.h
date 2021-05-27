#pragma once
#include <iostream>


class Node
{
protected:
	int data_;
	Node* pNext_;
public:
	Node();
	~Node();
	int getData();
	void setData(int data);
	Node* getpNext();
	void setpNext(Node* pNext);
	static Node* getNewNode(int data);

};

