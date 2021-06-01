#pragma once
#include "List.h"

void runProgram();
void exitProgram(bool& willExit);
void display(List * list, int nPet, int nDog);
void petHeaderInfo();
void petHeaderHealthCheck();
void untilNextHealthCheck(List * list);
void addPet(List *list);
List* createPetList();
void display(List *list);
void showRation(List *list);
void removePet(List *list);


