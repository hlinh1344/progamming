#include <iostream>
#include <string>
using namespace std;
#include "menu.h"

int main() {
    bool willExit = 0;
    int select;
    string yourString;
    cout << "\nPress '_' to end the string"<< endl <<"Enter a string : ";
    getline(cin, yourString, '_');
    cout << yourString<<"\n";
    menu(select, willExit,  yourString);
    return 0;
}

void menu(int& select, bool willExit,  string  yourString) {
    displayMenu();
    do {
        cin >> select;
        switch (select) {
        case 1:
            countNumberOfVowels(yourString);
            break;
        case 2:
            countNumberOfConsonants(yourString);
            break;
        case 3:
            convertToUppercase(yourString);
            break;
        case 4:
            convertToLowercase(yourString);
            break;
        case 5:
            displayTheCurrentStr(yourString);
            break;
        case 6:
            enterAnotherStr(yourString);
            break;
        case 7:
            displayMenu();
            break;
        case 8:
            exitProgram(willExit);
            break;
        default:
            break;
        }
    } while (!willExit);
}

void countNumberOfVowels( string  yourString) {
    system("cls");
    cout <<"\nNumber of vowels : "<< numberOfVowels( yourString) << endl;
    system("pause");
}

int numberOfVowels( string  yourString) {
    int numberOfVowels = 0;
    for (int i = 0; i < yourString.length(); i++) {
        if ((yourString[i] == 'A') || (yourString[i] == 'E') || (yourString[i] == 'I') || (yourString[i] == 'O') || (yourString[i] == 'U') || (yourString[i] == 'a') || (yourString[i] == 'e') || (yourString[i] == 'i') || (yourString[i] == 'o') || (yourString[i] == 'u')) {
            numberOfVowels = numberOfVowels + 1;
        }
    }
    return numberOfVowels;
}

void exitProgram(bool& willExit) {
    system("cls");
    willExit = 1;
    cout << "Goodbye!";
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 10000; j++) {
        }
    }
}

void displayMenu() {
    system("cls");
    cout << " 1)  Count the number of vowels in the string";
    cout << "\n 2)  Count the number of consonants in the string";
    cout << "\n 3)  Convert the string to uppercase";
    cout << "\n 4)  Convert the string to lowercase";
    cout << "\n 5)  Display the current string";
    cout << "\n 6)  Enter another string";
    cout << "\n 7)  Display this menu";
    cout << "\n 8)  Exit the program";
    cout << "\n";
    cout << "\n Enter your menu selection : ";

}

void countNumberOfConsonants( string  yourString) {
    system("cls");
    cout << "\nNumber of consonants : " << numberOfConsonants( yourString) << endl;
    system("pause");
}

int numberOfConsonants( string  yourString) {
    int alphanumericCharacters = 0;
    for (int i = 0; i < yourString.length(); i++) {
        if (((yourString[i] >= 65) && (yourString[i] <= 90)) || ((yourString[i] >= 97) && (yourString[i] <= 122)))
            alphanumericCharacters++;
    }
    return  alphanumericCharacters - numberOfVowels( yourString);
}

int numberOfSpaces( string  yourString) {
    int numberOfSpaces = 0;
    for (int i = 0; i < yourString.length(); i++) {
        if (yourString[i] == ' ') {
            numberOfSpaces++;
        }
    }
    return numberOfSpaces;
}

void convertToUppercase( string &yourString) {
    for (int i = 0; i < yourString.length(); i++) {
        if ((yourString[i] >=97) && (yourString[i] <= 122)) {
            yourString[i] = yourString[i] - 32;
        }
    }

}

void convertToLowercase(string& yourString) {

    for (int i = 0; i < yourString.length(); i++) {
        if ((yourString[i] >= 65) && (yourString[i] <= 90)) {
            yourString[i] = yourString[i] + 32;
        }
    }

}

void displayTheCurrentStr(string yourString) {
    system("cls");
    cout << "\nThe current string : " << yourString << endl;
    system("pause");
}

void enterAnotherStr(string& yourString) {
    system("cls");
    cout << "Please enter another string : ";
    getline(cin, yourString, '_');
    system("pause");
}