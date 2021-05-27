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
	void display();
	bool isEmpty();
	int countNumberOfNode();
	int calculateSum();
	int coutEvenElements();
	void printPositiveNode();
	void addNodeAfterK(Node* p, int k);
	void removeHead();
	void removeTail();
	void removeNodeAfterK(int k);

};

