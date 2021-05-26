#pragma once
#include "node.h"

class List : public Node
{
private:
	Node* pHead;
	Node* pTail;
public:
	List();
	~List();
	void addHead(Node* temp);
	void addTail(Node* temp);
	void display() const;
	bool isEmpty() const;
	
};

