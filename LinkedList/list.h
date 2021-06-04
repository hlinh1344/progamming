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
	void addNodeAfterK(int data, int k);
	Node* removeHead();
	Node* removeTail();
	void removeNodeHasKValue(int k);
	void removeNode(Node* &previous, Node* &current);
	void deleteNode(Node* &current);
	void addHead(int data);
	void addTail(int data);
};

