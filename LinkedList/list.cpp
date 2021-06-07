#include "list.h"

List::List() {
	head = nullptr;
	tail = nullptr;
}

List::~List() {
	Node* current = head;
	for (Node* current = head; current != nullptr;) {
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

void List::printList() {
	if (isEmpty()) {
		std::cout << "\nNo element in the list!!\n";
	}
	else {
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->getData() << "\t";
			current = current->getNext();
		}
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

int List::calculateSum() {
	int sum = 0;
	Node* current = head;
	while (current != nullptr) {
		sum += current->getData();
		current = current->getNext();
	}
	return sum;
}

int List::coutEvenElements() {
	int evenElements = 0;
	if (isEmpty())
		evenElements = 0;
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->getData() % 2 == 0)
				evenElements++;
			current = current->getNext();
		}
	}
	return evenElements;
}

void List::printPositiveNode() {
	Node* current = head;
	while (current != nullptr)
	{
		if ((current->getData()) >= 0)
			std::cout << current->getData() << "\t";
		current = current->getNext();
	}
}


void List::addNodeAfterK(int data, int k) {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else {
		Node* nodeK = findNode(k);
		if (nodeK == nullptr) {
			std::cout << "Node K is not in the list!";
		}
		else
		{
			Node* newNode = new Node(data);
			newNode->setNext(nodeK->getNext());
			nodeK->setNext(newNode);
			if (nodeK == tail)
			{
				tail = newNode;
			}
		}
	}

}

Node* List::findNode(int k) {
	Node* current = head;
	while (current != nullptr) {
		if (current->getData() == k) {
			break;
		}
		current = current->getNext();
	}
	return current;
}


Node* List::removeHead() {
	if (isEmpty()) {
		std::cout << "\nThe list is empty!!\n";
		head = nullptr;
	}
	else
	{
		removeNode(nullptr, head);
		std::cout << "The first element in the list was removed.";
	}

	return head;
}

Node* List::removeTail() {
	if (isEmpty()) {
		std::cout << "\nThe list is empty!!\n";
		tail = nullptr;
	}
	else {
		Node* current = head;
		Node* previous = nullptr;
		while (current != tail) {
			previous = current;
			current = current->getNext();
		}
		removeNode(previous, current);
		std::cout << "The last element in the list was removed.";
	}
	return tail;
}

void List::removeNodeHasKValue(int k) {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else {
		bool isHasKValue = false;
		Node* current = head;
		Node* previous = nullptr;
		while (current != nullptr)
		{
			if (current->getData() == k) {
				isHasKValue = true;
				removeNode(previous, current);
			}
			else {
				previous = current;
				current = current->getNext();
			}
		}
		if (isHasKValue)
			std::cout << "\nRemoved all elements have " << k << " value !";
		else
			std::cout << "\nNo element has " << k << " value.";
	}
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