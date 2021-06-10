#include "list.h"

List::List() {
	head = nullptr;
	tail = nullptr;
}

List::~List() {
	Node* current = nullptr;
	for ( current = head; current != nullptr;) {
		Node* nodeDestructed = current;
		current = current->getNext();
		deleteNode(nodeDestructed);
	}
	deleteNode(current);
}

void List::addHead(Node* p) {
	if (isEmpty()) {
		head = p;
		tail = p;
	}
	else {
		p->setNext(head);
		head = p;
	}

}

void List::addHead(int data) {
	Node* newHead = new Node(data);
	addHead(newHead);
}

void List::addTail(Node* p) {
	if (isEmpty()) {
		head = p;
		tail = p;
	}
	else {
		tail->setNext(p);
		tail = p;
	}

}

void List::addTail(int data) {
	Node* newTail = new Node(data);
	addTail(newTail);
}

void List::printList(std::ostream &os) {
	Node* current = head;
	while (current != nullptr) {
		os << current->getData() << "\n";
		current = (current->getNext());
	}
}

bool List::isEmpty() {
	if (head == nullptr)
		return true;
	return false;
}

int List::getSize() {
	int count = 0;
	if (isEmpty())
		count = 0;
	else
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->getNext();
		}
	}
	return count;
}

void List::removeNode(Node* previous, Node*& current) {
	if (current == head) {
		if (current == tail)
			tail = nullptr;
		Node* temp = head;
		head = head->getNext();
		deleteNode(temp);
		current = head;
	}
	else {
		if (current == tail)
			tail = previous;
		previous->setNext(current->getNext());
		deleteNode(current);
		current = previous->getNext();
	}
}

void List::deleteNode(Node*& current) {
	delete current;
	current = nullptr;
}

Node* List::getHead() {
	return head;
}
Node* List::getTail() {
	return tail;
}

void List::setHead(Node* a_head) {
	this->head = a_head;
}

void List::setTail(Node* a_tail) {
	this->head = a_tail;
}
