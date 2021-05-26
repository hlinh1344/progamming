#include "node.h"

Node::Node() {
	data_ = 0;
	pNext_ = nullptr;
}
Node::~Node() {
	pNext_ = NULL;
}

int Node::getData() {
	return data_;
}

void Node::setData(int data) {
	this->data_ = data;
}

Node* Node::getpNext() {
	return pNext_;
}

void Node::setpNext(Node* pNext) {
	this->pNext_ = pNext;
}

Node* Node::getNewNode(int data) {
	Node* newNode = new Node();
	if (newNode == NULL) {
		std::cout << "\nCan't create new node!\n";
		return NULL;
	}
	else {
		newNode->setData(data);
	}
	return newNode;
}
