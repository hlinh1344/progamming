#pragma once
#include "Node.h"

class List : public Node
{
private:
	Node* pHead;
	Node* pTail;
public:
	List();
	~List();
	void addTail(Node* p);
	bool isEmpty();
	void addHead(Node* p);
	void printList(std::ostream& os);
	void petInfoHeader();
	int getSize();
	void Ration();
	void petRationHeader();
	void petHealthCheckHeader();
	void showHealthCheck();
	void addPetToList(int type);
};