#include <iostream>
#include <iomanip>
#include <fstream>

#include "OrderItem.h"

void displayHeader();
void display(OrderItem* list, int& n);
void enterOrderList(OrderItem* &list, int& n);
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
            enterOrderList(list,  n);
            std::cout << "\n";
            system("pause");
            break;
        case 2:
            display(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 3:
            // TODO
            std::cout << "\n";
            system("pause");
            break;
        default:
            break;
        }
    } while (!willExit);
}


void displayHeader() {
    std::cout << "\n" << std::setw(25) << std::left << "Item Name" << std::setw(11) << std::right << "Rate" << std::setw(10) << std::right << "Qty" <<
        std::setw(13) << std::right << "Amount" << "\t" << std::setw(20) << std::left << "Note" << std::endl;
    std::cout << "---------------------------------------------------------------------------\n";
}
void display(OrderItem* list, int& n) {
    displayHeader();
    for (int i = 0; i < n; i++) {
        list[i].displayItem();
    }
}

void enterOrderList(OrderItem* &list, int &n) {
    std::cout << "\nNumber of dishes you want to order : ";
    std::cin >> n;
    list = new OrderItem[n];
    std::ofstream ofs("file.csv");
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::cout << "\n" << (i + 1) << ":\n";
        list[i].enterItemInfo();
        float itemAmount = list[i].getAmount();
        // do something on itemAmount
        //
        //
        //        
        // change item count, need to recalculate amount and get new amount
        list[i].valueOfItem();
        list[i].printToFile(ofs);
        itemAmount = list[i].getAmount();
    }
}

int main() {
    OrderItem* list;
    runProgram(list);
    system("pause");
    return 0;
}