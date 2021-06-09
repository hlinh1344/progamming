#pragma once
#include <iostream>
#include "Cat.h"
#include "Dog.h"

template <class T>
class Node
{
protected:
	T data;
	Node<T>* next;
public:
	Node();
	~Node();
	T getData();
	void setData(T data);
	Node<T>* getNext();
	void setNext(Node<T>* next);
	static Node<T>* getNewNode(std::istream& is)
	{
		Node<T>* newNode = new Node<T>();
		if (newNode == NULL) {
			std::cout << "\nCan't create new node!\n";
			return NULL;
		}
		else {
			char line[10] = {};
			is.getline(line, 100);
			if (line[0] == '1') {
				T newPet = new Dog();
				newPet->enterInfo(is);
				newNode->setData(newPet);
			}
			else if (line[0] == '2')
			{
				T newPet = new Cat();
				newPet->enterInfo(is);
				newNode->setData(newPet);
			}
		}
		return newNode;
	}

};


template <class T>
Node<T>::Node() {
	next = nullptr;
}

template <class T>
Node<T>::~Node() {
	next = NULL;
}

template <class T>
T Node<T>::getData() {
	return data;
}

template <class T>
void Node<T>::setData(T a_data) {
	this->data = a_data;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <class T>
void Node<T>::setNext(Node<T>* a_next) {
	this->next = a_next;
}
