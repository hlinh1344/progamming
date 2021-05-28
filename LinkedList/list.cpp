#include "list.h"

List::List() {
	pHead = nullptr;
	pTail = nullptr;
}

List::~List() {
	Node* temp = pHead;
	while (temp != nullptr) {
		Node* nodeDistructed = temp;
		temp = (temp->getpNext());
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
		p->setpNext(pHead);
		pHead = p;
	}

}


void List::addTail(Node* p) {
	if (isEmpty()) {
		pHead = p;
		pTail = p;
	}
	else {
		pTail->setpNext(p);
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
			current = (current->getpNext());
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
			temp = (temp->getpNext());
		}
	}
	return nCount;
}

int List::calculateSum() {
	int sum = 0;
	Node* current = pHead;
	while (current != nullptr) {
		sum += current->getData();
		current = current->getpNext();
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
			current = (current->getpNext());
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
		current = (current->getpNext());
	}
}

void List::addNodeAfterK(Node* p, int k) {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else {
		Node* current = pHead;
		while (current != nullptr)
		{
			if (current->getData() == k) {
				p->setpNext(current->getpNext());
				current->setpNext(p);
				std::cout << "\nAdded a node after the first element has "<< k <<" value !";
				break;
			}
			current = (current->getpNext());
			if (current == nullptr)
				std::cout << "\nNo element has data is " << k << " in the list";
		}
	}

}

void List::removeHead() {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else
	{
		pHead = pHead->getpNext();
		std::cout << "The first element in the list was removed.";
	}
}

void List::removeTail() {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else
	{
		Node* previous = pHead;
		Node* current = previous->getpNext();
		while (current->getpNext() != nullptr) {
			current = current->getpNext();
			previous = previous->getpNext();
		}
		previous->setpNext(nullptr);
		std::cout << "The last element in the list was removed.";
	}

}

void List::removeNodeHasKValue(int k) {
	if (isEmpty())
		std::cout << "\nThe list is empty!!\n";
	else {
		bool isHasKValue = false;
		Node* current = pHead;
		Node* previous = new Node();
		previous->setpNext(current);
		while (current != nullptr)
		{
			if (current->getData() == k) {
				isHasKValue = true;
				if (current == pHead) {
					pHead = pHead->getpNext();
					current = current->getpNext();
					previous->setpNext(current);
				}
				else
				{
					previous->setpNext(current->getpNext());
					current = current->getpNext();
				}
			}
			else {
				previous = previous->getpNext();
				current = current->getpNext();
			}
		}

		if (isHasKValue)
			std::cout << "\nRemoved all elements have " << k << " value !";
		else
			std::cout << "\nNo element has "<< k << " value.";
	}
}