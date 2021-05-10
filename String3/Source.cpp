#include <iostream>
#include "pch.h"


int main() {
    bool willExit = 0;
    int select;
    std::cout << "\nEnter the string : ";
    char* yourString =  new char[100];
    
    std::cin.getline(yourString, 100);
    int stringLength = length(yourString);
    menu(select, willExit, yourString, stringLength);
    delete []yourString;
    system("pause");
    return 0;

}
