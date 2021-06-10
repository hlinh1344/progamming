#pragma once
#include "node.h"

class List 
{
private:
	Node* head;
	Node* tail;
public:
	List();
	~List();

	void addHead(Node* p);
	void addTail(Node* p);
	void printList(std::ostream & os);
	bool isEmpty();
	int getSize();
	void removeNode(Node* previous, Node*& current);
	void deleteNode(Node*& current);
	Node* getHead();
	Node* getTail();
	void setHead(Node* a_head);
	void setTail(Node* a_tail);
	void addHead(int data);
	void addTail(int data);

};

