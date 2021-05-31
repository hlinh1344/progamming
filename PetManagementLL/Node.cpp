#include "Node.h"

Node::Node() {
	pNext_ = nullptr;
}
Node::~Node() {
	pNext_ = NULL;
}

Pet *Node::getData() {
	return data_;
}

void Node::setData(Pet *data) {
	this->data_ = data;
}

Node* Node::getpNext() {
	return pNext_;
}

void Node::setpNext(Node* pNext) {
	this->pNext_ = pNext;
}

Node* Node::getNewNode(std::istream& is) {
	Node* newNode = new Node();
	if (newNode == NULL) {
		std::cout << "\nCan't create new node!\n";
		return NULL;
	}
	else {
		char line[10] = {};
		is.getline(line, 100);
		if (line[0] == '1') {
			Pet* newPet = new Dog();
			newPet->enterInfo(is);
			newNode->setData(newPet);
		}
		else if (line[0] == '2')
		{
			Pet* newPet = new Cat();
			newPet->enterInfo(is);
			newNode->setData(newPet);
		}
	}
	return newNode;
}
