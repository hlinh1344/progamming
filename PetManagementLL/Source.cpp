

#include <time.h>
#include <fstream>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Header.h"
#include "List.h"

int main() {
    runProgram();
    system("pause");
    return 0;
}

void runProgram() {
    List* list = new List;
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
            list = createPetList();
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

void display(List* list) {
    list->printList(std::cout);
}





void untilNextHealthCheck(List * list) {
    list->showHealthCheck();
}


List* createPetList() {
    std::ifstream myFile("petInfo.txt");
    List* newList = new List;
    if (myFile.is_open()) {
        while (!myFile.eof())
        {
             newList->addTail(Node::getNewNode(myFile));
        }
        std::cout << "\nCreate the list of pet from file!\n";
        myFile.close();
    }
    else {
        std::cout << "\nCan't open file\n";
        newList = nullptr;
    }
    return newList;
}

void showRation(List* list) {
    list->Ration();
}

void addPet(List* list) {
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
    list->addPetToList(type);
}

void removePet(List* list) {
    int idRemove;
    int listSize = list->getSize();
    do {
        std::cout << "\nEnter ID number of pet you want to remove : ";
        std::cin >> idRemove;
        if ((idRemove < 1) || (idRemove > listSize)) {
            std::cout << "\n\nThe ID you entered is wrong, please re-enter!\n";
        }
    } while ((idRemove < 1) || (idRemove > listSize));
    list->removeNode(idRemove);
}