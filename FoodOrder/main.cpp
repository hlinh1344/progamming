#include <iostream>
#include <iomanip>
#include <fstream>
#include "FoodItems.h"


int main() {    
    OrderItem* list;
    runProgram(list); // runProgram
    delete[]list;
    system("pause");
    return 0;
}

void runProgram(OrderItem*& list) {
    bool willExit = false;
    int n = 0;
    do {
        system("cls");
        std::cout << "---------------------------------------------------------------------------" << std::endl;
        std::cout << "1. Enter the order list from the keyboard.\n";
        std::cout << "2. Enter the order list from the file.\n";
        std::cout << "3. Total price for each dish.\n";
        std::cout << "4. Sort food order list in descengsing according to the number of dishes.\n";
        std::cout << "5. Total value of payment (included 15.000 VND shipping fee).\n";
        std::cout << "6. Export the food bill to CSV format  .\n";
        std::cout << "7. Exit program.\n";
        std::cout << "8. Enter order list from keyboard using overloading >> operator.\n";
        std::cout << "---------------------------------------------------------------------------" << std::endl;
        std::cout << "Select a action you want to do : ";
        int select;
        std::cin >> select;
        switch (select) {
        case 1:
            enterOrderList(list, n);
            valueOfAllItems(list, n);
            break;
        case 2:
            readFoodOrderList(list, n);
            valueOfAllItems(list, n);
            std::cout << "\n";
            system("pause");
            break;
            break;
        case 3:
            allItemInfo(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 4:
            bubbleSort(list, n);
            display(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 5:
            display(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 6:
            calculateBill(list, n);
            std::cout << "\n";
            system("pause");
            break;

        case 7:
            exitProgram(willExit);
            break;
        case 8:
            enterOrderList2(list, n);
            valueOfAllItems(list, n);
            break;
        default:
            break;
        }
    } while (!willExit);
}