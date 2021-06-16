#pragma once
#include <iostream>

template <class T>
class Node
{
protected:
	T data;
	Node<T>* next;
public:
	Node();
	Node(T a_data);
	Node(T a_data, Node<T>* a_next);
	~Node();
	T getData();
	void setData(T data);
	Node<T>* getNext();
	void setNext(Node<T>* next);
};

template <class T>
Node<T>::Node()
{
	next = nullptr;
}

template <class T>
Node<T>::Node(T a_data) 
{
	data = a_data;
}

template <class T>
Node<T>::Node(T a_data, Node<T>* a_next)
{
	data = a_data;
	next = a_next;
}

template <class T>
Node<T>::~Node() 
{
	next = NULL;
}

template <class T>
T Node<T>::getData()
{
	return data;
}

template <class T>
void Node<T>::setData(T a_data)
{
	this->data = a_data;
}

template <class T>
Node<T>* Node<T>::getNext() 
{
	return next;
}

template <class T>
void Node<T>::setNext(Node<T>* a_next) 
{
	this->next = a_next;
}