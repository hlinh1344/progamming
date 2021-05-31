#pragma once
#include "List.h"

void runProgram();
void exitProgram(bool& willExit);
//void readPetList(List* &list, int& nPet, int& nDog, int& nCat);
void display(List * list, int nPet, int nDog);
void petHeaderInfo();
//void calculateRation(Pet** list, int nPet, int nDog);
//void untilNextHealthCheck(Pet** list, int nPet, int nDog);
void petHeaderHealthCheck();
void untilNextHealthCheck(List * list);
void addPet(List *list);
List* createPetList();
void display(List *list);
void showRation(List *list);



