#pragma once
#include "node.h"
#include "list.h"
#include "source.h"

int main() {
	runProgram();
	system("pause");
	return 0;
}

void runProgram() {
    List* list = nullptr;
	bool willExit = false;
	int select;
	do {
        system("cls");
        std::cout << "1.Create a new list.\n";
        std::cout << "2.Display the list.\n";
        std::cout << "3.Sum of all elements in the list.\n";
        std::cout << "4.Count the number of all elements in the list.\n";
        std::cout << "5.Count the number of even elements in the list.\n";
        std::cout << "6.Print positive elements in the list.\n";
        std::cout << "7.Add an element to the beginning of the list.\n";
        std::cout << "8.Add an element after value 'k' of the list.\n";
        std::cout << "9.Remove the first element of the list.\n";
        std::cout << "10.Remove the last element of the list.\n";
        std::cout << "11.Remove all elements with value 'k' of the list.\n";
        std::cout << "12.Exit.\n";
        std::cout << "------------------------------------------\n";
        std::cout << "Select a number : ";
        std::cin >> select;
        std::cout << "\n\n";

        switch (select)
        {
        case 1:
            createList(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 2:
            displayList(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 3:
            sumList(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 4:
            calculateNumberOfElements(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 5:
            calculateNumberOEvenElements(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 6:
            printPositiveElements(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 7:
            addFirst(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 8:
            addAfterValueK(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 9:
            removeFirst(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 10:
            removeLast(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 11:
            removeAfterValueK(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 12:
            delete list;
            list = nullptr;
            exitProgram(willExit);
            std::cout << "\nBye!\n\n";
            system("pause");
            break;
        default:
            break;
        }
	} while (!willExit);
  
}

void exitProgram(bool& willExit){
    willExit = true;
}


void displayList(List *list) {
    if (list->isEmpty()) 
        std::cout << "\nNo element in the list!!\n";
    else
    list->printList(std::cout);
}

void createList(List* &list) {
    delete list;
    list = nullptr;
    list = new List();
    std::cout << "\nNumber of elements of the list : ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ".";
        std::cout << "data : ";
        int data;
        std::cin >> data;
        Node* newNode = new Node(data);
        list->addTail(newNode);
    }
}

void addFirst(List* list) {
    std::cout << "data : ";
    int data;
    std::cin >> data;
    Node* newNode = new Node(data);
    list->addHead(newNode);
}


void addAfterValueK(List* list) {
    if (list->isEmpty())
        std::cout << "\nNo element in the list!!\n";
    else
    {
        std::cout << "\nEnter K value : ";
        int kValue;
        std::cin >> kValue;
        Node* nodeK = findNode(list, kValue);
        if (nodeK == nullptr) {
            std::cout << "Node K is not in the list!";
        }
        else
        {
            std::cout << "Enter data you want to add : ";
            int data;
            std::cin >> data;
            Node* newNode = new Node(data);
            newNode->setNext(nodeK->getNext());
            nodeK->setNext(newNode);
            if (nodeK == list->getTail())
                list->setTail(newNode);
        }
    }
}

void sumList(List* list) {
    int sum = 0;
    Node* current = list->getHead();
    while (current != nullptr) {
        sum += current->getData();
        current = current->getNext();
    }
    std::cout << "\nSum of all elements in the list : " << sum;
}

void calculateNumberOfElements( List *list) {
    int numberOfNode = list->getSize();
    std::cout << "\nNumber of elements : " << numberOfNode;
}

void calculateNumberOEvenElements(List* list) {
    int evenElements = 0;
    if (list->isEmpty())
        evenElements = 0;
    else
    {
        Node* current = list->getHead();
        while (current != nullptr)
        {
            if (current->getData() % 2 == 0)
                evenElements++;
            current = current->getNext();
        }
    }
    std::cout << "\nNumber of even elements : " << evenElements;
}

void printPositiveElements(List* list) {
    Node* current = list->getHead();
    while (current != nullptr)
    {
        if ((current->getData()) >= 0)
            std::cout << current->getData() << "\t";
        current = current->getNext();
    }
}

void removeFirst(List* list) {
    if (list->isEmpty())
        std::cout << "\nThe list is empty!!\n";
    else
    {
        Node* head = list->getHead();
        list->removeNode(nullptr, head);
        std::cout << "The first element in the list was removed.";
    }
}

void removeLast(List* list) {
    if (list->isEmpty())
        std::cout << "\nTthe list is empty!!\n";
    else {
        Node* current = list->getHead();
        Node* previous = nullptr;
        while (current != list->getTail()) {
            previous = current;
            current = current->getNext();
        }
        list->removeNode(previous, current);
        std::cout << "The last element in the list was removed.";
    }
}

void removeAfterValueK(List* list) {
    if (list->isEmpty())
        std::cout << "\ninthe list is empty!!\n";
    else {
        std::cout << "Enter K value : ";
        int kValue;
        std::cin >> kValue;
        bool isHasKValue = false;
        Node* current = list->getHead();
        Node* previous = nullptr;
        while (current != nullptr)
        {
            if (current->getData() == kValue) {
                isHasKValue = true;
                list->removeNode(previous, current);
            }
            else {
                previous = current;
                current = current->getNext();
            }
        }
        if (isHasKValue)
            std::cout << "\nRemoved all elements have " << kValue << " value !";
        else
            std::cout << "\nNo element has " << kValue << " value.";
    }
}

Node* findNode(List* list, int k) {
    Node* current = list->getHead();
    while (current != nullptr) {
        if (current->getData() == k) {
            break;
        }
        current = current->getNext();
    }
    return current;
}