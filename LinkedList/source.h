#pragma once
void runProgram();
bool exitProgram(bool &willExit);
void displayList(List *list);
List *createList();
void addFirst(List* list);
void addLast(List* list);
void addAfterValueK(List* list);
void sumList(List *list);
void calculateNumberOfElements(List *list);
void calculateNumberOEvenElements(List* list);
void printPositiveElements(List* list);
void removeFirst(List* list);
void removeLast(List* list);
void removeAfterValueK(List* list);