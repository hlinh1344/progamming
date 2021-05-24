#include <iostream>
#include <iomanip>
#include <fstream>

#include "OrderItem.h"
void displayHeader();
void display(OrderItem* list, int& n);
void enterOrderList(OrderItem*& list, int& n);
void showAllItemInfo(OrderItem* list, int n);
void runProgram();
void readOrderList(OrderItem*& list, int& n);
void bubbleSort(OrderItem* list, int n);
void swap(OrderItem& itemA, OrderItem& itemB);
void printBilll(OrderItem* list, int n);
void exitProgram(bool& willExit);
void enterOrderList2(OrderItem*& list, int& n);


int main() {
   // OrderItem* list;
    runProgram();
    system("pause");
    return 0;
}

void runProgram() {
    OrderItem* list = new OrderItem[1];
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
            readOrderList(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 3:
            showAllItemInfo(list, n);
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
            printBilll(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 7:
            exitProgram(willExit);
            break;
        case 8:
            enterOrderList2(list, n);
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
  
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::cout << "\n" << (i + 1) << ":\n";
        list[i].enterItemInfo();
        list[i].valueOfItem();
    }
}

void showAllItemInfo(OrderItem* list, int n) {
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        list[i].showItemInfo();
    }
}

void readOrderList(OrderItem*& list, int& n) {
    list = new OrderItem[200];
    std::ifstream myFile("GrabFoodOrderList.txt");
    if (myFile.is_open()) {
        char line[100] = {};
        int i = 0;        
        while (!myFile.eof())
        {
            myFile >> list[i];
            list[i].valueOfItem();
            i++;
        }
        n = i;
        system("cls");
        std::cout << "Read GrabFoodOrderList.txt is finished! ";
    }

    else {
        std::cout << "\nCan't open GrabFoodOrderList.txt\n";
    }
    myFile.close();
}

void bubbleSort(OrderItem* list, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (list[j].getQuantity() > list[j+1].getQuantity())
                swap(list[j],list[j+1]);
}


void swap(OrderItem& itemA, OrderItem& itemB) {
    OrderItem itemC;
    itemC = itemA;
    itemA = itemB;
    itemB = itemC;
}

void printBilll(OrderItem* list, int n) {
    std::ofstream foodBillCSV;
    foodBillCSV.open("FoodOrderBill.csv");
    if (foodBillCSV.is_open()) {
        int subTotal = 0;
        int itemsSold = 0;
        for (int i = 0; i < n; i++) {
            list[i].printToFile(foodBillCSV);
            subTotal = subTotal + list[i].getAmount();
            itemsSold = itemsSold + list[i].getQuantity();
        }
        int total = subTotal + 15000;
        foodBillCSV << "TOTAL," << total;
        std::cout << "Your bill in FoodOrderBill.csv\n";
    }
    else {
        std::cout << "\nCan't open FoodOrderBill.csv \n";
    }
    foodBillCSV.close();
}

void exitProgram(bool& willExit) {
    willExit = true;
}

void enterOrderList2(OrderItem*& list, int& n) {
    std::cout << "\nNumber of dishes you want to order : ";
    std::cin >> n;
    list = new OrderItem[n];
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::cout << "\n" << (i + 1) << ":\n";
        std::cin >> list[i];
        list[i].valueOfItem();
    }

}
