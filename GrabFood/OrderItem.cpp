#include <iostream>
#include <string>
#include <iomanip>
#include "OrderItem.h"

OrderItem::OrderItem() {
}

OrderItem::~OrderItem() {
}

std::string OrderItem::getName() {
    return name;
}

void OrderItem::setName(std::string name) {
    this->name = name;
}

std::string OrderItem::getNote() {
    return note;
}

void OrderItem::setNote(std::string note) {
    this->note = note;
}

int OrderItem::getRate() {
    return rate;
}

void OrderItem::setRate(int rate) {
    this->rate = rate;
}

int OrderItem::getQuantity() {
    return quantity;
}

void OrderItem::setQuantity(int quantity) {
    this->quantity = quantity;
}

int OrderItem::getAmount() {
    return amount;
}

void OrderItem::enterItemInfo() {
    std::cout << "\tName : ";
    getline(std::cin, name);
    std::cout << "\tQuantity : ";
    std::cin >> quantity;
    std::cout << "\tRate : ";
    std::cin >> rate;
    std::cout << "\tNote : ";
    std::cin.ignore();
    getline(std::cin, note);
}

void OrderItem::valueOfItem() {
    amount = rate * quantity;
}

void OrderItem::displayItem() {
    std::cout << std::setw(25) << std::left << name << std::setw(11) << std::right << rate << std::setw(10) << std::right << quantity <<
        std::setw(13) << std::right << amount << "\t" << std::setw(20) << std::left << note << std::endl;
}

void OrderItem::printToFile(std::ostream& os)
{
    os << name << "," << rate << "," << quantity <<
        "," << amount << "," << note << std::endl;
}

void OrderItem::showItemInfo() {
    std::cout << std::setw(30) << std::left << name << std::setw(5) << std::right << "x" << quantity
        << std::setw(10) << std::right << amount << " VND" << std::endl;
}



std::istream& operator >> (std::istream& is, OrderItem& Item)
{
    std::cout << "\tName : ";
    getline(is, Item.name);

    std::cout << "\tQuatity : ";
    is >> Item.quantity;

    std::cout << "\tRate : ";
    is >> Item.rate;

    is.ignore();
    std::cout << "\tNote : ";
    getline(is, Item.note);

    return is;
}