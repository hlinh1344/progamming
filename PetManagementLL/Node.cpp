#include "Node.h"

template <class T>
Node<T>::Node() {
	next_ = nullptr;
}

template <class T>
Node<T>::~Node() {
	next_ = NULL;
}

template <class T>
T Node<T>::getData() {
	return data_;
}

template <class T>
void Node<T>::setData(T data) {
	this->data_ = data;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return next_;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
	this->next_ = next;
}

template <class T>
Node<T>* getNewNode(std::istream& is) {
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
