// pch.cpp: source file corresponding to the pre-compiled header
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "FoodItems.h"
#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.



void enterOrderList(OrderItem* &list, int &n) {
    std::cout << "\nNumber of dishes you want to order : ";
    std::cin >> n;
    list = new OrderItem[n];
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::cout << "\n" << (i + 1) << ":\n";
        enterItem(list[i]);
    }
}
void enterItem(OrderItem &item) {
        std::cout << "\tName : ";
        std::cin.getline(item.name, 100);
        std::cout << "\tQuantity : ";
        std::cin >> item.quantity;
        std::cout << "\tRate : ";
        std::cin >> item.rate;
        std::cout << "\tNote : ";
        std::cin.ignore();
        std::cin.getline(item.note, 100);
}

void valueOfAllItems(OrderItem* list, int n) {
    for (int i = 0; i < n; i++) {
        valueOfEachItem(list[i]);
    }
}

void valueOfEachItem(OrderItem &item) {
        item.amount = item.rate * item.quantity;
}

void display(OrderItem* list, int n) {
    displayHeader();
    std::cout << "---------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
    displayItem(list[i]);
    }
}

void displayHeader() {
    std::cout << "\n" << std::setw(25) << std::left << "Item Name" << std::setw(11) << std::right << "Rate" << std::setw(10) << std::right << "Qty" <<
        std::setw(13) << std::right << "Amount" << "\t" << std::setw(20) << std::left << "Note" << std::endl;
}

void displayItem(OrderItem &item) {
        std::cout << std::setw(25) << std::left << item.name << std::setw(11) << std::right << item.rate << std::setw(10) << std::right << item.quantity <<
            std::setw(13) << std::right << item.amount << "\t" << std::setw(20) << std::left << item.note << std::endl; 
}
void exitProgram(bool& willExit) {
    willExit = 1;
}

void allItemInfo(OrderItem* list, int n) {
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        itemInfo(list[i]);
    }
}

void itemInfo(OrderItem item) {
    std::cout << std::setw(30) << std::left << item.name << std::setw(5) << std::right << "x" << item.quantity
        << std::setw(10) << std::right << item.amount << " VND" << std::endl;
}

void bubbleSort(OrderItem* list, int n) {
    int i, j;
    for (i = (n - 1); i >= 0; i--) {
        for (j = 1; j <= i; j++) {
            if (list[j - 1].quantity > list[j].quantity)
                swap(list[j - 1], list[j]);
        }
    }
}

void swap(OrderItem& a, OrderItem& b) {
    OrderItem temp = a;
    a = b;
    b = temp;
}

//calculateBill
void calculateBill(OrderItem* list, int n) {
    std::ofstream foodBill;
    foodBill.open("FoodOrderBill.txt");
    if (foodBill.is_open()) {
        int subTotal = 0;
        int itemsSold = 0;
        foodBill << "\n\n";
        foodBill << std::setw(35) << std::right << "NOWFOODY" << std::endl;
        foodBill << std::setw(37) << std::right << "www.foody.vn" << std::endl;
        foodBill << "\n\n";
        foodBill << std::setw(25) << std::left << "Item Name" << std::setw(11) << std::right 
            << "Rate" << std::setw(10) << std::right << "Qty" <<std::setw(13) << std::right 
            << "Amount" << "\t" << std::setw(20) << std::left << "Note" << std::endl;

        foodBill << "---------------------------------------------------------------------------\n";

        for (int i = 0; i < n; i++) {
            foodBill << std::setw(25) << std::left << list[i].name << std::setw(11) << std::right 
                << list[i].rate << std::setw(10) << std::right << list[i].quantity <<std::setw(13) 
                << std::right << list[i].amount << "\t" << std::setw(20) << std::left << list[i].note << std::endl;

            subTotal = subTotal + list[i].amount;
            itemsSold = itemsSold + list[i].quantity;
        }
        int total = subTotal + 15000;

        foodBill << "---------------------------------------------------------------------------\n";

        foodBill  << std::setw(36) << std::left << "ITEMS SOLD :"
            << std::setw(10) << std::right << itemsSold << std::endl;
        foodBill << std::setw(46) << std::left << "SUB TOTAL :"
            << std::setw(13) << std::right << subTotal << " VND" << std::endl;
        foodBill << std::setw(46) << std::left << "SALE :"
            << std::setw(13) << std::right << "0.0" << " VND" << std::endl;
        foodBill << std::setw(46) << std::left << "SERVICE FEE :"
            << std::setw(13) << std::right << 2000 << " VND" << std::endl;
        foodBill << std::setw(46) << std::left << "DELIVERY FEE :"
            << std::setw(13) << std::right << 13000 << " VND" << std::endl;

        foodBill << "---------------------------------------------------------------------------\n";

        foodBill << std::setw(46) << std::left << "TOTAL :"
            << std::setw(13) << std::right << total << " VND" << std::endl;
    }
    else {
        std::cout << "\nCan't open FoodOrderBill.txt \n";
    }
    foodBill.close();


    //export CSV file
    std::ofstream foodBillCSV;
    foodBillCSV.open("FoodOrderBill.csv");
    if (foodBillCSV.is_open()) {
        int subTotal = 0;
        int itemsSold = 0;
        for (int i = 0; i < n; i++) {
            foodBillCSV << list[i].name << "," << list[i].rate << "," << list[i].quantity <<
                "," << list[i].amount << "," << list[i].note << std::endl;
            subTotal = subTotal + list[i].amount;
            itemsSold = itemsSold + list[i].quantity;
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

void readFoodOrderList(OrderItem* &list, int &n) {    
    list = new OrderItem[200];
    std::ifstream myFile("FoodOrderList.txt");
    if (myFile.is_open()) {
        char line[100] = {};
        int i = 0;
        while (!myFile.eof())
        {            
            myFile.getline(list[i].name, 100);
            std::cout << list[i].name << '\n';

            myFile.getline(line, 100);
            list[i].quantity = atoi(line);
         
            std::cout << list[i].quantity << '\n';

            myFile.getline(line, 100);
            list[i].rate = atoi(line);
            std::cout << list[i].rate << '\n';

            myFile.getline(list[i].note, 100);
            std::cout << list[i].note << "\n";
            std::cout << "------\n";
            
            i++;
        }
        n = i;
    }

    else {
        std::cout << "\nCan't open FoodOrderList.txt\n";
    }
    myFile.close();
}


std::istream& operator>> (std::istream& is, OrderItem& Item)
{
    std::cout << "\tName : ";
    is.getline(Item.name, 100);

    std::cout << "\tQuatity : ";
    is >> Item.quantity;

    std::cout << "\tRate : ";
    is >> Item.rate;

    is.ignore();
    std::cout << "\tNote : ";
    is.getline(Item.note, 100);

    return is;
}

void enterOrderList2(OrderItem* &list, int& n) {
    std::cout << "\nNumber of dishes you want to order : ";
    std::cin >> n;
    list = new OrderItem[n];
    std::cin.ignore();

    for (int i = 0; i < n; i++) {
        std::cout << "\n" << (i + 1) << ":\n";
        std::cin >> list[i];
    }
    
}