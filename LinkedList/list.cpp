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
	if (pHead == nullptr) {
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
	if (pHead == nullptr) {
		pHead = p;
		pTail = p;
	}
	else {
		
		Node* previous = pHead;
		Node* current = previous->getpNext();
		
		//After while loop ,previous = pTail
		while (current != nullptr) {
			current = (current->getpNext());
			previous = (previous->getpNext());
		}
		previous->setpNext(p);
	}

}

void List::display() const {
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

bool List::isEmpty() const {
	if (pHead == nullptr)
		return true;
	return false;
}



