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
    List *list = new List;
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
            list = createList();
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
            exitProgram(willExit);
            std::cout << "\nBye!\n\n";
            system("pause");
            break;
        default:
            break;
        }
	} while (!willExit);

}

bool exitProgram(bool& willExit) {
    willExit = true;
    return willExit;
}


void displayList(List *list) {
    list->printList();
}

List *createList() {
    std::cout << "\nNumber of elements of the list : ";
    int n;
    std::cin >> n;
    List* newList = new List;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1<< ".";
        std::cout << "data : ";
        int data;
        std::cin >> data;
        newList->addTail(new Node(data));
    }
    return newList;
}

void addFirst(List* list) {
    std::cout << "data : ";
    int data;
    std::cin >> data;
    list->addHead(new Node(data));
}


void addAfterValueK(List* list) {
    std::cout << "Enter K value : ";
    int kValue;
    std::cin >> kValue;
    std::cout << "Enter data you want to add : ";
    int data;
    std::cin >> data;
    list->addNodeAfterK(data, kValue);
}

void sumList(List *list) {
    int sumAllElements = list->calculateSum();
    std::cout << "\nSum of all elements in the list : "<< sumAllElements;
}

void calculateNumberOfElements( List *list) {
    int numberOfNode = list->getSize();
    std::cout << "\nNumber of elements : " << numberOfNode;
}

void calculateNumberOEvenElements(List* list) {
    int numberOfEvenElements = list->coutEvenElements();
    std::cout << "\nNumber of even elements : " << numberOfEvenElements;
}

void printPositiveElements(List* list) {
    list->printPositiveNode();
}

void removeFirst(List* list) {
    Node* newHead = list->removeHead();
}

void removeLast(List* list) {
    list->removeTail();
}

void removeAfterValueK(List* list) {
    std::cout << "Enter K value : ";
    int kValue;
    std::cin >> kValue;
    list->removeNodeHasKValue(kValue);
}