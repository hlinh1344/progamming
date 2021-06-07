#include "List.h"

template <class T>
List<T>::List<T>() {
	head = nullptr;
	tail = nullptr;
}

template <class T>
List<T>::~List<T>() {
	Node <T>* temp = head;
	while (temp != nullptr) {
		Node* nodeDistructed = temp;
		temp = (temp->getNext());
		delete nodeDistructed;
		nodeDistructed = NULL;
	}
}

template <class T>
void List<T>::addTail(Node<T>* p) {
	if (isEmpty()) {
		head = p;
		tail = p;
	}
	else {
		tail->setNext(p);
		tail = p;
	}

}

template <class T>
bool List<T>::isEmpty() {
	if (head == nullptr)
		return true;
	return false;
}
template <class T>
void List<T>::addHead(Node<T>* p) {
	if (isEmpty()) {
		head = p;
		tail = p;
	}
	else {
		p->setNext(head);
		head = p;
	}

}

template <class T>
void List<T>::printList(std::ostream& os) {
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

template <class T>
void List<T>::petInfoHeader() {
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(10) << std::right << "Weight"
		<< std::setw(10) << std::right << "Length"
		<< std::setw(10) << std::right << "Height"
		<< std::setw(25) << std::right << "Breed"
		<< std::setw(25) << std::right << "Hair color" << std::endl;
}

template <class T>
int List<T>::getSize() {
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
template <class T>
void List<T>::Ration() {
	List::petRationHeader();
	int n = 1;
	Node* current = head;
	while (current != nullptr) {
		std::cout << std::setw(3) << std::right << n++;
		current->getData()->showPetRation();
		current = (current->getNext());
	}
}

template <class T>
void List<T>::petRationHeader() {
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(25) << std::right << "Morning ration"
		<< std::setw(25) << std::right << "Afternoon ration" << std::endl;
}

template <class T>
void List<T>::petHealthCheckHeader() {
	std::cout << std::setw(3) << std::right << "ID"
		<< std::setw(7) << std::right << "Type"
		<< std::setw(30) << std::right << "Recent health check day"
		<< std::setw(30) << std::right << "The next health check day"
		<< std::setw(25) << std::right << "Remaining days" << std::endl;
}

template <class T>
void List<T>::showHealthCheck() {
	List::petHealthCheckHeader();
	Node* current = head;
	int i = 1;
	while (current != nullptr) {
		std::cout << std::setw(3) << std::right << i++;
		current->getData()->showPetHealCheckInfo();
		current = (current->getNext());
	}
}

template <class T>
void List<T>::addPetToList(int type) {
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

template <class T>
void List<T>::removeNode(Node<T>* previous, Node<T>*& current) {
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

template <class T>
void List<T>::deleteNode(Node<T> *current) {
	delete current;
	current = nullptr;
}

template <class T>
Node<T>* List<T>::findNode(int id) {
	Node<T>* current = head;
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

template <class T>
void List<T>::remove(int id) {
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