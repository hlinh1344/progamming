#include "List.h"
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

bool List::isEmpty() {
	if (pHead == nullptr)
		return true;
	return false;
}

void List::addHead(Node* p) {
	if (isEmpty()) {
		pHead = p;
		pTail = p;
	}
	else {
		p->setpNext(pHead);
		pHead = p;
	}

}

void List::printList(std::ostream& os) {
	if (isEmpty()) {
		std::cout << "\nNo element in the list!!\n";
	}
	else {
		List::petInfoHeader();
		int n = 1;
		Node* current = pHead;
		while (current != nullptr) {
			os << std::setw(3) << std::right << n++;
			current->getData()->showPetInfo(os);
			current = (current->getpNext());
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
		Node* temp = pHead;
		while (temp != nullptr)
		{
			nCount++;
			temp = (temp->getpNext());
		}
	}
	return nCount;
}

void List::Ration() {
	List::petRationHeader();
	int n = 1;
	Node* current = pHead;
	while (current != nullptr) {
		std::cout << std::setw(3) << std::right << n++;
		current->getData()->showPetRation();
		current = (current->getpNext());
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
	Node* current = pHead;
	int i = 1;
	while (current != nullptr) {
		std::cout << std::setw(3) << std::right << i++;
		current->getData()->showPetHealCheckInfo();
		current = (current->getpNext());
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

void List::removeNode(int idRemove) {
	if (idRemove == 1) {
		pHead = pHead->getpNext();
	}
	else
	{
		Node* current = pHead;
		//move current pointer to the previous idRemove
		for (int i = 1; i < idRemove - 1; i++) {
			current = current->getpNext();
		}
		current->setpNext(current->getpNext()->getpNext());
	}
	std::cout << "\n\nThe pet has been removed from the list !\n";
}