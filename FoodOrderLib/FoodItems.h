// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.
#pragma once
#include "framework.h"
#ifndef FOODORDER_EXPORTS
#define FOODORDER_API __declspec(dllexport)
#else
#define FOODORDER_API __declspec(dllimport)

// add headers that you want to pre-compile here


#endif //PCH_H
FOODORDER_API struct OrderItem {
    char name[100] = {};
    int quantity = 0;
    int rate = 0;
    char note[100] = {};
    int amount = 0;
};

FOODORDER_API void runProgram(OrderItem* &list);
FOODORDER_API void display(OrderItem* list, int n);
FOODORDER_API void enterOrderList(OrderItem* &list, int& n);
FOODORDER_API void exitProgram(bool& willExit);
FOODORDER_API void swap(OrderItem& a, OrderItem& b);
FOODORDER_API void bubbleSort(OrderItem* list, int n);
FOODORDER_API void calculateBill(OrderItem* list, int n);
FOODORDER_API void readFoodOrderList(OrderItem* &list, int &n);
FOODORDER_API void enterItem(OrderItem &item);
FOODORDER_API void displayItem(OrderItem& item);
FOODORDER_API void displayHeader();
FOODORDER_API void allItemInfo(OrderItem* list, int n);
FOODORDER_API void itemInfo(OrderItem item);
FOODORDER_API void valueOfEachItem(OrderItem& item);
FOODORDER_API void valueOfAllItems(OrderItem* list, int n);
FOODORDER_API void enterOrderList2(OrderItem* &list, int& n);