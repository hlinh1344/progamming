
#include <vector>
#include <time.h>
#include <fstream>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"

#define _CRT_SECURE_NO_WARNINGS


void runProgram(Pet** list);
void exitProgram(bool& willExit);
void readPetList(Pet** list, int& nPet, int& nDog, int& nCat);
void display(Pet** list, int nPet, int nDog);
void petHeaderInfo();
void calculateRation(Pet** list, int nPet, int nDog);
void untilNextHealthCheck(Pet** list, int nPet, int nDog);
void petHeaderHealthCheck();
void untilNextHealthCheck(Pet** list, int nPet, int nDog);

int main() {


    //time_t t = time(NULL);   // get time now
    //tm now;
    //localtime_s(&now, &t);
    //
    //printDate(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);

    Pet* petList[1024];    
    runProgram(petList);
    system("pause");
    return 0;
} 

void runProgram(Pet** list){
    bool willExit = false;
    int select;
    int nDog = 0;
    int nPet = 0;
    int nCat = 0;
    do {
        system("cls");
        std::cout << "1.Enter all pet's properties from file.\n";
        std::cout << "2.Display information of all pet.\n";
        std::cout << "3.Show pet's (morning & afternoon) ration.\n";
        std::cout << "4.Calculate number of days until the next health check day.\n";
        std::cout << "5.Exit.\n";
        std::cout << "------------------------------------------\n";
        std::cout << "Select a number : ";
        std::cin >> select;
        std::cout << "\n\n";

        switch (select)
        {
        case 1:
            readPetList(list,nPet, nDog, nCat);
            system("pause");
            std::cout << "\n\n";
            break;
        case 2:
            display(list, nPet, nDog);
            std::cout << "\n\n";
            system("pause");
            break;
        case 3:
            calculateRation(list, nPet, nDog);
            std::cout << "\n\n";
            system("pause");
            break;
        case 4:
            untilNextHealthCheck(list, nPet, nDog);
            std::cout << "\n\n";
            system("pause");
            break;
        case 5:
            exitProgram(willExit);
            std::cout << "\nBye!\n\n";
            system("pause");
            break;

        default:
            break;
        }
    }
    while (!willExit);
}
void exitProgram(bool &willExit) {
    willExit = true;
}

void readPetList(Pet **list, int& nPet, int& nDog, int& nCat) {

   std::ifstream myFile("PetInfo.txt");
    //std::istream myFile(std::cin);
    if (myFile.is_open()) {
        char line[100] = {};
       // char t = 1;
        int i = 0;
        while (!myFile.eof())
        {
            myFile.getline(line, 100);
            if (line[0] == '1') {                                
                list[i] = new Dog();            
            }
            else if(line[0] == '2') {
                list[i] = new Cat();
                nCat++;
            }

            list[i]->enterInfo(myFile);

            i++;
        }
        nPet = i;
        std::cout << "\nFinished reading list of all pet! \n\n\n";
    }

    else {
        std::cout << "\nCan't open file\n";
    }
    myFile.close();
}



void display(Pet** list, int nPet, int nDog) {
    petHeaderInfo();

    for (int i = 0; i < nPet; i++) {
        std::cout << std::setw(3) << std::right << i+1;
        list[i]->petInfo(std::cout);
    }
}

void petHeaderInfo() {
    std::cout << std::setw(3) << std::right << "ID"
        << std::setw(7) << std::right << "Type"
        << std::setw(10) << std::right << "Weight"
        << std::setw(10) << std::right << "Length"
        << std::setw(10) << std::right << "Height"
        << std::setw(25) << std::right << "Breed"
        << std::setw(25) << std::right << "Hair color" << std::endl;
}

void petHeaderRation() {
    std::cout << std::setw(3) << std::right << "ID"
        << std::setw(7) << std::right << "Type"
        << std::setw(25) << std::right << "Morning ration"
        << std::setw(25) << std::right << "Afternoon ration" << std::endl;
}

void calculateRation(Pet** list, int nPet, int nDog) {
    petHeaderRation();
    for (int i = 0; i < nPet; i++) {
        std::cout << std::setw(3) << std::right << i + 1;
        list[i]->showPetRation();
    }
}

void petHeaderHealthCheck() {
    std::cout << std::setw(3) << std::right << "ID"
        << std::setw(7) << std::right << "Type"
        << std::setw(30) << std::right << "Recent health check day"
        << std::setw(30) << std::right << "The next health check day"
        << std::setw(25) << std::right << "Remaining days" << std::endl;
}

void untilNextHealthCheck(Pet** list, int nPet, int nDog) {
    petHeaderHealthCheck();
    for (int i = 0; i < nPet; i++) {
        std::cout << std::setw(3) << std::right << i + 1;
        list[i]->showPetHealCheckInfo();
    }

}