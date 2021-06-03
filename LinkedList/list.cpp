#include "list.h"

List::List() {
	pHead = nullptr;
	pTail = nullptr;
}

List::~List() {
	Node* current = pHead;
	while (current != nullptr) {
		Node* nodeDistructed = current;
		current = (current->getNext());
		delete nodeDistructed;
		nodeDistructed = NULL;
	}
}

void List::addHead(Node * p) {
	if (isEmpty()) {
		pHead = p;
		pTail = p;
	}
	else {
		p->setNext(pHead);
		pHead = p;
	}

}


void List::addTail(Node* p) {
	if (isEmpty()) {
		pHead = p;
		pTail = p;
	}
	else {
		pTail->setNext(p);
		pTail = p;
	}

}

void List::printList(){
	if (isEmpty()) {
		std::cout << "\nNo element in the list!!\n";
	}
	else {
		Node* current = pHead;
		while (current != nullptr) {
			std::cout << current->getData() << "\t";
			current = (current->getNext());
		}
	}
}

bool List::isEmpty() {
	if (pHead == nullptr)
		return true;
	return false;
}

int List::getSize() {
	int nCount = 0;
	if (isEmpty())
		nCount= 0;
	else
	{
		Node* temp = pHead;
		while (temp != nullptr)
		{
			nCount++;
			temp = (temp->getNext());
		}
	}
	return nCount;
}

int List::calculateSum() {
	int sum = 0;
	Node* current = pHead;
	while (current != nullptr) {
		sum += current->getData();
		current = current->getNext();
	}
	return sum;
}

int List::coutEvenElements() {
	int countEven = 0;
	if (isEmpty())
		countEven = 0;
	else
	{
		Node* current = pHead;
		while (current != nullptr)
		{
			if ((current->getData()) % 2 == 0)
				countEven++;
			current = (current->getNext());
		}
	}
	return countEven;
}

void List::printPositiveNode() {
	Node* current= pHead;
	while (current != nullptr)
	{
		if ((current->getData()) >= 0)
			std::cout << current->getData() <<"\t";
		current = (current->getNext());
	}
}


void List::addNodeAfterK(int data, int k) {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else {
		Node* current = pHead;
		while (current != nullptr)
		{
			if (current->getData() == k) {
				Node* newNode = new Node(data, current->getNext());
				current->setNext(newNode);
				std::cout << "\nAdded a node after the first element has " << k << " value !";
				break;
			}
			current = (current->getNext());
			if (current == nullptr)
				std::cout << "\nNo element has data is " << k << " in the list";
		}
	}

}

Node* List::removeHead() {
	if (isEmpty()) {
		std::cout << "\nThe list is empty!!\n";
		pHead = nullptr;
	}
	else
	{
		Node* current = pHead;
		Node* previous = new Node();
		previous->setNext(current);
		removeNode(previous, current);
		std::cout << "The first element in the list was removed.";
	}

	return pHead;
}

Node* List::removeTail() {
	if (isEmpty()) {
		std::cout << "\nThe list is empty!!\n";
		pTail = nullptr;
	}
	else {
		Node* current = pHead;
		Node* previous = new Node();
		previous->setNext(current);
		while (current != pTail) {
			current = current->getNext();
			previous = previous->getNext();
		}
		removeNode(previous, current);
		std::cout << "The last element in the list was removed.";
	}
	return pTail;
}

void List::removeNodeHasKValue(int k) {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else {
		bool isHasKValue = false;
		Node* current = pHead;
		Node* previous = new Node();
		previous->setNext(current);
		while (current != nullptr)
		{
			if (current->getData() == k) {
				isHasKValue = true;
				removeNode(previous, current);
			}
			else {
				previous = previous->getNext();
				current = current->getNext();
			}
		}

		if (isHasKValue)
			std::cout << "\nRemoved all elements have " << k << " value !";
		else
			std::cout << "\nNo element has "<< k << " value.";
	}
}

void List::removeNode(Node * &previous, Node * &current) {
	if (current == pHead) {
		Node* temp = pHead;
		pHead = pHead->getNext();
		deleteNode(temp);
		current = pHead;
		previous->setNext(current);
	}
	else {
		previous->setNext(current->getNext());
		deleteNode(current);
		current = previous->getNext();
	}
}

void List::deleteNode(Node* &current) {
	delete current;
	current = nullptr;
}