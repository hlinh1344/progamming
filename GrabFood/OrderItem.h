#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class OrderItem
{
private:
    std::string name;
    int rate;
    int quantity;
    std::string note;
    int amount;

public:
    OrderItem();
    ~OrderItem();
    std::string getName();
    void setName(std::string name);
    std::string getNote();
    void setNote(std::string note);
    int getRate();
    void setRate(int rate);
    int getQuantity();
    void setQuantity(int quantity);
    int calculateAmount();
    void enterItemInfo();
    void valueOfItem();
    void displayItem();
    void printToFile(std::ostream &os);
    void showItemInfo();
    friend std::istream& operator>> (std::istream& is, OrderItem& Item); // global operator
};
