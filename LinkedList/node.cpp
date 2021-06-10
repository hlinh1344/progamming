#include "Node.h"

 Node::Node() {
	next = nullptr;
}

Node::Node(int a_data) {
	data = a_data;
}

 Node::Node(int a_data, Node* a_next) {
	data = a_data;
	next = a_next;
}

 Node::~Node() {
	next = NULL;
}

int Node::getData() {
	return data;
}

void Node::setData(int a_data) {
	this->data = a_data;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* a_next) {
	this->next = a_next;
}