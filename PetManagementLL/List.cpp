#include "List.h"
List::List() {
	head = nullptr;
	tail = nullptr;
}

List::~List() {
	Node* temp = head;
	while (temp != nullptr) {
		Node* nodeDistructed = temp;
		temp = (temp->getNext());
		delete nodeDistructed;
		nodeDistructed = NULL;
	}
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

bool List::isEmpty() {
	if (head == nullptr)
		return true;
	return false;
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

void List::printList(std::ostream& os) {
	if (isEmpty()) {
		std::cout << "\nNo element in the list!!\n";
	}
	else {
		List::petInfoHeader();
		int n = 1;
		Node* current = head;
		while (current != nullptr) {
			os << std::setw(3) << std::right << n++;
			current->getData()->showPetInfo(os);
			current = (current->getNext());
		}
	}
}

void List::petInfoHeader() {
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(10) << std::right << "Weight"
		<< std::setw(10) << std::right << "Length"
		<< std::setw(10) << std::right << "Height"
		<< std::setw(25) << std::right << "Breed"
		<< std::setw(25) << std::right << "Hair color" << std::endl;
}

int List::getSize() {
	int nCount = 0;
	if (isEmpty())
		nCount = 0;
	else
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			nCount++;
			temp = (temp->getNext());
		}
	}
	return nCount;
}

void List::Ration() {
	List::petRationHeader();
	int n = 1;
	Node* current = head;
	while (current != nullptr) {
		std::cout << std::setw(3) << std::right << n++;
		current->getData()->showPetRation();
		current = (current->getNext());
	}
}

void List::petRationHeader() {
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(25) << std::right << "Morning ration"
		<< std::setw(25) << std::right << "Afternoon ration" << std::endl;
}

void List::petHealthCheckHeader() {
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(30) << std::right << "Recent health check day"
		<< std::setw(30) << std::right << "The next health check day"
		<< std::setw(25) << std::right << "Remaining days" << std::endl;
}

void List::showHealthCheck() {
	List::petHealthCheckHeader();
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		std::cout << std::setw(3) << std::right << i++;
		current->getData()->showPetHealCheckInfo();
		current = (current->getNext());
	}
}

void List::addPetToList(int type) {
	Node* newNode = new Node();
	if (type == 1) {
		Pet* newPet = new Dog();
		newPet->addPet();
		newNode->setData(newPet);
	}
	else if(type == 2) {
		Pet* newPet = new Cat();
		newPet->addPet();
		newNode->setData(newPet);
	}
	addHead(newNode);
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

void List::deleteNode(Node *current) {
	delete current;
	current = nullptr;
}

Node* List::findNode(int id) {
	Node* current = head;
	int idNumber = 0;
	while (current != nullptr) {
		idNumber++;
		if (id == idNumber) {
			break;
		}
		current = current->getNext();
	}
	return current;
}

void List::remove(int id) {
	if (isEmpty()) {
		std::cout << "\nThe list is empty!!\n";
		head = nullptr;
	}
	else {
		Node* current = head;
		Node* previous = nullptr;
		int idNumber = 0;
		while (current != nullptr) {
			idNumber++;
			if (id == idNumber) {
				break;
			}
			previous = current;
			current = current->getNext();
		}
		removeNode(previous, current);
	}
	
}