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

	void addHead(Node* p);
	void addTail(Node* p);
	void printList();
	bool isEmpty();
	int getSize();
	int calculateSum();
	int coutEvenElements();
	void printPositiveNode();
	void addNodeAfterK(Node* p, int k);
	void removeHead();
	void removeTail();
	void removeNodeHasKValue(int k);

};

