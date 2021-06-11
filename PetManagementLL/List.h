#pragma once
#include "Node.h"
//#include <string> 

template <class T>
class List 
{
private:
	Node<T>* head ;
	Node<T>* tail;
public:
	List();
	~List();
	
	void addHead(Node<T>* p);
	void addTail(Node<T>* p);
	void printList(std::ostream& os);
	bool isEmpty();
	int getSize();
	void removeNode(Node<T>* previous, Node<T>*& current);
	void deleteNode(Node<T>* current);
	Node<T>* getHead();
	Node<T>* getTail();
	void setHead(Node<T>* a_head);
	void setTail(Node<T>* a_tail);
	void addHead(T data);
	void addTail(T data);
	friend std::ostream& operator << (std::ostream& os, Pet* a_data);
};


template <class T>
void List<T>::addTail(T data)
{
	Node* newTail = new Node(data);
	addTail(newTail);
}

template <class T>
void List<T>::addHead(T data)
{
	Node* newHead = new Node(data);
	addHead(newHead);
}

template <class T>
Node<T>* List<T>::getHead() 
{
	return head;
}

template <class T>
Node<T>* List<T>::getTail()
{
	return tail;
}

template <class T>
void List<T>::setHead(Node<T>* a_head)
{
	this->head = a_head;
}

template <class T>
void List<T>::setTail(Node<T>* a_tail)
{
	this->head = a_tail;
}

template <class T>
List<T>::List<T>() 
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
List<T>::~List<T>()
{
	Node <T>* temp = head;
	while (temp != nullptr) 
	{
		Node<T>* nodeDistructed = temp;
		temp = (temp->getNext());
		delete nodeDistructed;
		nodeDistructed = NULL;
	}
}

template <class T>
void List<T>::addTail(Node<T>* p)
{
	if (isEmpty())
	{
		head = p;
		tail = p;
	}
	else {
		tail->setNext(p);
		tail = p;
	}

}

template <class T>
bool List<T>::isEmpty() 
{
	if (head == nullptr)
		return true;
	return false;
}

template <class T>
void List<T>::addHead(Node<T>* p)
{
	if (isEmpty()) 
	{
		head = p;
		tail = p;
	}
	else 
	{
		p->setNext(head);
		head = p;
	}

}

int n = 1;
template <class T>
void List<T>::printList(std::ostream& os)
{
	Node<T>* current = head;
	while (current != nullptr) 
	{
		os << current->getData();
		current = (current->getNext());
	}
	n = 1;
}

template <class T>
int List<T>::getSize() 
{
	int count = 0;
	if (isEmpty())
		count = 0;
	else
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = (temp->getNext());
		}
	}
	return count;
}

template <class T>
void List<T>::removeNode(Node<T>* previous, Node<T>*& current) 
{
	if (current == head) 
	{
		if (current == tail)
			tail = nullptr;
		Node<T>* temp = head;
		head = head->getNext();
		deleteNode(temp);
		current = head;
	}
	else 
	{
		if (current == tail)
			tail = previous;
		previous->setNext(current->getNext());
		deleteNode(current);
		current = previous->getNext();
	}
}

template <class T>
void List<T>::deleteNode(Node<T>* current)
{
	delete current;
	current = nullptr;
}

std::ostream& operator << (std::ostream& os, Pet* a_data)
{
	os << std::setw(3) << std::right;
	if (n < 10) {
		std::string ID;
		ID = "0" + std::to_string(n++);
		os << ID;
	}
	else {
		std::string ID;
		ID = std::to_string(n++);
		os << ID;
	}

	os << std::setw(7) << std::right;

	if (a_data->getType() == 1)
		os << "Dog";
	else if (a_data->getType() == 2) 
		os << "Cat";

	os << std::setw(10) << std::right << a_data->getWeight()
		<< std::setw(10) << std::right << a_data->getLength()
		<< std::setw(10) << std::right << a_data->getHeight()
		<< std::setw(25) << std::right << a_data->getBreed()
		<< std::setw(25) << std::right << a_data->getHairColor() << std::endl;
	return os;
}