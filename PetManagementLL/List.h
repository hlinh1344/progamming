#pragma once
#include "Node.h"

template <class T>
class List : public Node<T>
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List();
	~List();
	void addTail(Node<T>* p);
	bool isEmpty();
	void addHead(Node<T>* p);
	void printList(std::ostream& os);
	void petInfoHeader();
	int getSize();
	void Ration();
	void petRationHeader();
	void petHealthCheckHeader();
	void showHealthCheck();
	void addPetToList(int type);
	void removeNode(Node<T>* previous, Node<T>*& current);
	void deleteNode(Node<T>* current);
	Node<T>* findNode(int id);
	void remove(int id);
};