#include <iostream>
#include <iomanip>
#include <fstream>
//#include <string>
//#include <cstdlib>
//#include "OrderHeader.h"

struct OrderItem {
    char *name = new char[100];
    int quantity;
    int rate;
    char *note = new char[100];
    int amount;
};

void enterOrderList(OrderItem* list, int& n);
void menu(OrderItem* list);
void display(OrderItem* list, int n);

void exitProgram(bool& willExit);
void amountEachItem(OrderItem* list, int n);
void swap(OrderItem& a, OrderItem& b);
void bubbleSort(OrderItem* list, int n);
void bill(OrderItem* list, int n);
void readFoodOrderList(OrderItem* list, int n);


int main() {
    OrderItem a[100] = {};
    OrderItem* list = a;
    menu(list);
    system("pause");
    return 0;
}

void menu(OrderItem *list) {
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
        std::cout << "---------------------------------------------------------------------------" << std::endl;
        std::cout << "Select a action you want to do : ";
        int select;
        std::cin >> select; 
        switch (select) {
        case 1:
            enterOrderList(list, n);
            break;
        case 2:
            readFoodOrderList(list, n);
            std::cout << "\n";
            system("pause");
            break;
            break;
        case 3:
            amountEachItem(list, n);
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
            bill(list, n);
            std::cout << "\n";
            system("pause");
            break;
        case 6:
            display(list, n);
            std::cout << "\n";
            system("pause");
            break;
            
        case 7:
            exitProgram(willExit);
            break;
        default:
            break;
        }
    } while (!willExit);
}

void enterOrderList(OrderItem* list,int &n) {
    std::cout << "\nNumber of dishes you want to order : ";
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::cout << "\n" << i+1 << ".Name : ";
        std::cin.getline(list[i].name, 100);
        std::cout << i + 1 << ".Quantity : ";
        std::cin >> list[i].quantity;
        std::cout <<i+1 << ".Rate : ";
        std::cin >> list[i].rate;
        std::cout  << i + 1 << ".Note : ";
        std::cin.ignore();
        std::cin.getline(list[i].note, 256);
        list[i].amount = list[i].rate * list[i].quantity;
    }
}

void display(OrderItem* list, int n) {

    std::cout << "\n" << std::setw(25) << std::left << "Item Name" << std::setw(11)<< std::right << "Rate"<< std::setw(10)<< std::right << "Qty"<<
        std::setw(13)<< std::right<< "Amount" << "\t"<<std::setw(20)<<std:: left << "Note"<<std::endl;
    for (int i = 0; i < 15; i++) {
        std::cout << "-----";
    }
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(25) << std::left << list[i].name << std::setw(11) << std::right << list[i].rate  << std::setw(10) << std::right << list[i].quantity <<
            std::setw(13) << std::right << list[i].amount <<  "\t" << std::setw(20) << std::left << list[i].note << std::endl;

    }
}

void exitProgram(bool& willExit) {
    willExit = 1;
}

void amountEachItem(OrderItem* list, int n) {
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(30)<<std::left<< list[i].name <<std::setw(5)<<std::right <<"x"<< list[i].quantity
            << std::setw(10)<<std::right << list[i].amount  << " VND" << std::endl;
    }
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

void swap(OrderItem &a, OrderItem &b) {
    OrderItem temp = a;
    a = b;
    b = temp;
}

void bill(OrderItem* list, int n) {
    std::ofstream foodBill;
    foodBill.open("FoodOrderBill.txt");
    if (foodBill.is_open()) {
        int subTotal = 0;
        int itemsSold = 0;
        foodBill << "\n\n";
        foodBill << std::setw(35) << std::right << "NOWFOODY" << std::endl;
        foodBill << std::setw(37) << std::right << "www.foody.vn" << std::endl;
        foodBill << "\n\n";
        foodBill << std::setw(25) << std::left << "Item Name" << std::setw(11) << std::right << "Rate" << std::setw(10) << std::right << "Qty" <<
            std::setw(13) << std::right << "Amount" << "\t" << std::setw(20) << std::left << "Note" << std::endl;
        for (int i = 0; i < 15; i++) {
            foodBill << "-----";
        }
        foodBill << "\n";
        for (int i = 0; i < n; i++) {
            foodBill << std::setw(25) << std::left << list[i].name << std::setw(11) << std::right << list[i].rate << std::setw(10) << std::right << list[i].quantity <<
                std::setw(13) << std::right << list[i].amount << "\t" << std::setw(20) << std::left << list[i].note << std::endl;
            subTotal = subTotal + list[i].amount;
            itemsSold = itemsSold + list[i].quantity;
        }
        int total = subTotal + 15000;

        for (int i = 0; i < 15; i++) {
            foodBill << "-----";
        }
        foodBill << "\n" << std::setw(36) << std::left << "ITEMS SOLD :"
            << std::setw(10) << std::right << itemsSold << std::endl;
        foodBill << std::setw(46) << std::left << "SUB TOTAL :"
            << std::setw(13) << std::right << subTotal << " VND" << std::endl;
        foodBill << std::setw(46) << std::left << "SALE :"
            << std::setw(13) << std::right << "0.0" << " VND" << std::endl;
        foodBill << std::setw(46) << std::left << "SERVICE FEE :"
            << std::setw(13) << std::right << 2000 << " VND" << std::endl;
        foodBill << std::setw(46) << std::left << "DELIVERY FEE :"
            << std::setw(13) << std::right << 13000 << " VND" << std::endl;

        for (int i = 0; i < 15; i++) {
            foodBill << "-----";
        }

        foodBill << "\n" << std::setw(46) << std::left << "TOTAL :"
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
        foodBillCSV <<list[i].name << "\n" <<list[i].rate << "\n"<<list[i].quantity <<
                "\n"<< list[i].amount << "\n" << list[i].note <<"\n"<< std::endl;
            subTotal = subTotal + list[i].amount;
            itemsSold = itemsSold + list[i].quantity;
        }
        int total = subTotal + 15000;

         foodBillCSV << "-----\n";

        foodBillCSV << "\n" << std::setw(46) << std::left << "TOTAL :"
            << std::setw(13) << std::right << total << " VND" << std::endl;
    }
    else {
        std::cout << "\nCan't open FoodOrderBill.csv \n";
    }

    foodBillCSV.close();

}

void readFoodOrderList(OrderItem* list, int n) {

    std::ifstream myFile ("FoodOrderList.txt");
    if (myFile.is_open()) {
        char line[100] = {};
        int i = 0;
        char kt;
        while (!myFile.eof())
        {
            myFile.getline(line,100,'\n');
            list[i].name = line;
            std::cout << list[i].name << '\n';

            myFile.getline(line, 100, '\n');
            list[i].quantity = atoi(line);
            std::cout << list[i].quantity << '\n';

            myFile.getline(line, 100, '\n');
            list[i].rate = atoi(line);
            std::cout << list[i].rate << '\n';

            myFile.getline(line, 100, '\n');
            list[i].note = line;
            std::cout << list[i].note << '\n';
            
            i++;
        }
    }
    else {
        std::cout << "\nCan't open FoodOrderList.txt\n";
    }
    myFile.close();
}

