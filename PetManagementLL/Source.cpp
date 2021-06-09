

#include <time.h>
#include <fstream>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Header.h"
#include "List.h"

//template <class T>
int main() {
    runProgram();
    system("pause");
    return 0;
}


void runProgram() {
    List<Pet*>* list = new  List<Pet*>;
    bool willExit = false;
    int select;
    do {
        system("cls");
        std::cout << "1.Enter all pet's properties from file.\n";
        std::cout << "2.Display information of all pet.\n";
        std::cout << "3.Show pet's (morning & afternoon) ration.\n";
        std::cout << "4.Calculate number of days until the next health check day.\n";
        std::cout << "5.Add a Pet to the List.\n";
        std::cout << "6.Remove a Pet from the List.\n";
        std::cout << "7.Exit.\n";
        std::cout << "------------------------------------------\n";
        std::cout << "Select a number : ";
        std::cin >> select;
        std::cout << "\n\n";

        switch (select)
        {
        case 1:
            createPetList(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 2:
            display(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 3:
            showRation(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 4:
            untilNextHealthCheck(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 5:
            addPet(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 6:
            removePet(list);
            std::cout << "\n\n";
            system("pause");
            break;
        case 7:
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
void exitProgram(bool& willExit) {
    willExit = true;
}

void display(List<Pet*>* list) {
    list->printList(std::cout);
}

void untilNextHealthCheck(List<Pet*> * list) {
    list->showHealthCheck();
}

void createPetList(List<Pet*> *list) {
    std::ifstream myFile("petInfo.txt");
    if (myFile.is_open()) {
        while (!myFile.eof())
        {
             list->addTail(Node<Pet*>::getNewNode(myFile));
        }
        std::cout << "\nCreate the list of pet from file!\n";
        myFile.close();
    }
    else {
        std::cout << "\nCan't open file\n";
        list = nullptr;
    }
}

void showRation(List<Pet*>* list) {
    list->Ration();
}

void addPet(List<Pet*>* list) {
    int type;
    do {
        std::cout << "\nPress 1 or 2 to select the pet you want to add:";
        std::cout << "\n1. Dog\t\t2. Cat\n";
        std::cout << "\nYour selection: ";
        std::cin >> type;
        if ((type != 1) && (type != 2)) {
            std::cout << "\n\nPlease choose again !\n";
        }  
    } while ((type != 1) && (type != 2));

    Node<Pet*>* newNode = new Node<Pet*>();
    if (type == 1) {
        Pet* newPet = new Dog();
        newPet->addPet();
        newNode->setData(newPet);
    }
    else if (type == 2) {
        Pet* newPet = new Cat();
        newPet->addPet();
        newNode->setData(newPet);
    }
    list->addHead(newNode);

}

void removePet(List<Pet*>* list) {
    int idRemove;
    int listSize = list->getSize();
    if (list->isEmpty()) 
        std::cout << "\nThe list is empty!!\n";
    else {
        std::cout << "\nEnter ID number of pet you want to remove : ";
        std::cin >> idRemove;
        Node<Pet*>* current = list->getHead();
        Node<Pet*>* previous = nullptr;
        int idNumber = 0;
        while (current != nullptr) {
            idNumber++;
            if (idRemove == idNumber) {
                break;
            }
            previous = current;
            current = current->getNext();
        }
        if (current == nullptr)
            std::cout << "No Pet has ID = " << idRemove << " ! ";
        else 
            list->removeNode(previous, current);
    }
}