#pragma once
void runProgram();
void exitProgram(bool& willExit);
void displayList(List<int>* list);
void createList(List<int>*& list);
void addFirst(List<int>* list);
void addAfterValueK(List<int>* list);
void calculateNumberOfElements(List<int>* list);
void calculateNumberOEvenElements(List<int>* list);
void printPositiveElements(List<int>* list);
void removeFirst(List<int>* list);
void removeLast(List<int>* list);
void removeAfterValueK(List<int>* list);
Node<int>* findNode(List<int>* list, int k);
void sumList(List<int>* list);