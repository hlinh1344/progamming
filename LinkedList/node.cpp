#include "node.h"

Node::Node() {
	data = 0;
	next = nullptr;
}

Node::Node(int a_data) {
	data = a_data;
	next = nullptr;
}

Node::Node(int a_data, Node* a_next) {
	data = a_data;
	next = a_next;
}

Node::~Node() {
	data = 0;
	next = NULL;
}

int Node::getData() {
	return data;
}

void Node::setData(int data) {
	this->data = data;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* next) {
	this->next = next;
}

//Node* Node::getNewNode(int data) {
//	Node* newNode = new Node();
//	if (newNode == NULL) {
//		std::cout << "\nCan't create new node!\n";
//		return NULL;
//	}
//	else {
//		newNode->setData(data);
//	}
//	return newNode;
//}
