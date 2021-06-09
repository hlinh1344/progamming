#pragma once
#include "List.h"

void runProgram();
void exitProgram(bool& willExit);
void display(List<Pet*>* list);
void petHeaderInfo();
void petHeaderHealthCheck();
void untilNextHealthCheck(List <Pet*> * list);
void addPet(List<Pet*> *list);
void createPetList(List<Pet*>* list);
void display(List<Pet*> *list);
void showRation(List<Pet*> *list);
void removePet(List<Pet*> *list);


