#include "list.h"

List::List() {
	pHead = nullptr;
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
		Node* temp = pHead;
		pHead = p;
		pHead->setpNext(temp);
	}

}


void List::addTail(Node* p) {
	if (isEmpty()) {
		pHead = p;
		pTail = p;
	}
	else {
		Node* current = pHead;
		while (current->getpNext() != nullptr) {
			current = (current->getpNext());
		}
		current->setpNext(p);
	}

}

void List::display(){
	if (isEmpty()) {
		std::cout << "\nNo element in the list!!\n";
	}
	else {
		Node* temp = pHead;
		while (temp != nullptr) {
			std::cout << temp->getData() << "\t";
			temp = (temp->getpNext());
		}
	}
	
}

bool List::isEmpty() {
	if (pHead == nullptr)
		return true;
	return false;
}

int List::countNumberOfNode() {
	int count = 0;
	if (isEmpty())
		count = 0;
	else
	{
		Node* temp = pHead;
		while (temp != nullptr)
		{
			temp = (temp->getpNext());
			count++;
		}
	}
	return count;
}

int List::calculateSum() {
	int sum = 0;
	Node* temp = pHead;
	while (temp != nullptr) {
		sum += temp->getData();
		temp = temp->getpNext();
	}
	return sum;
}

int List::coutEvenElements() {
	int countEven = 0;
	if (isEmpty())
		countEven = 0;
	else
	{
		Node* temp = pHead;
		while (temp != nullptr)
		{
			if ((temp->getData()) % 2 == 0)
				countEven++;
			temp = (temp->getpNext());
		}
	}
	return countEven;
}

void List::printPositiveNode() {
	Node* temp = pHead;
	while (temp != nullptr)
	{
		if ((temp->getData()) >= 0)
			std::cout << temp->getData() <<"\t";
		temp = (temp->getpNext());
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

void List::removeNodeAfterK(int k) {
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
				previous->setpNext(current->getpNext());
				current = current->getpNext();
			}
			else {
				previous = previous->getpNext();
				current = current->getpNext();
			}
		}

		if (isHasKValue) {
			while(pHead->getData() == k) {
				pHead = pHead->getpNext();
				if (pHead == nullptr)
					break;
			}
			std::cout << "\nRemoved all elements have " << k << " value !";
		}
		else {
			std::cout << "\nNo element has "<< k << " value.";
		}
		
	}
}