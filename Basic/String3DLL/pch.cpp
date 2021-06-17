// pch.cpp: source file corresponding to the pre-compiled header
#include <iostream>
#include <string>
#include "pch.h"

// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
void menu(int& select, bool willExit, char* yourString, int& stringLength) {
    do {
        system("cls");
        std::cout << "1.Remove all trailing blanks from the right end of the string.\n";
        std::cout << "2.Remove all trailing blanks from the left end of the string.\n";
        std::cout << "3.Add extra blanks to the right end of the string.\n";
        std::cout << "4.Add extra blanks to the left end of the string.\n";
        std::cout << "5.Center the string.\n";
        std::cout << "6.Check Palindrome string.\n";
        std::cout << "7.Shorten the string to n characters.\n";
        std::cout << "8.Capitalizes the first letter in every word.\n";
        std::cout << "9.Capitalizes the first letter in the sring.\n";
        std::cout << "10.Check all characters (are Alphabetic?).\n";
        std::cout << "11.Reverses the characters in the string.\n";
        std::cout << "12.Counts the occurrences of a character in the string.\n";
        std::cout << "13.Counts the occurrences (of all characters in the second string) in the first string. \n";
        std::cout << "14.Delete all occurrences of a character in the string.\n";
        std::cout << "15.Exit the program\n";
        std::cout << "Select a action you want to do: ";
        std::cin >> select;

        int n;
        char c;
        int count_c;
        char* secondString;
        switch (select) {
        case 1:
            trimRight(yourString, stringLength);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 2:
            trimLeft(yourString, stringLength);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 3:

            std::cout << "\nenter the minimum length of string: ";
            std::cin >> n;
            padRight(yourString, stringLength, n);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 4:
            std::cout << "\nenter the minimum length of string: ";
            std::cin >> n;
            padLeft(yourString, stringLength, n);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 5:
            center(yourString, stringLength);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 6:
            if (isPalindrome(yourString, stringLength))
                std::cout << "\n" << yourString << " is a palindrome\n";
            else
                std::cout << "\n" << yourString << " is NOT a palindrome\n";
            system("pause");
            break;
        case 7:
            std::cout << "\nenter the maximum length of string: ";
            std::cin >> n;
            truncate(yourString, stringLength, n);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 8:
            capitalizeWords(yourString, stringLength);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 9:
            capitalize(yourString, stringLength);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 10:
            if (isAlpha(yourString, stringLength))
                std::cout << "\nAll characters in the parameter are alphabetic.\n";
            else
                std::cout << "\nAll characters in the parameter are NOT alphabetic.\n";
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 11:
            reverseString(yourString, stringLength);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 12:
            std::cout << "\nEnter a character you want to count : ";
            std::cin >> c;
            count_c = count(yourString, c, stringLength);
            std::cout << "\nNumbers of "<< c <<" in the string : "<< count_c<< std::endl;
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 13:
            secondString = new char[100];
            std::cout << "\nEnter a second string : ";
            std::cin.ignore();
            std::cin.getline(secondString, 100);
            count(yourString, stringLength,secondString);
            delete[]secondString;
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 14:
            std::cout << "\nEnter a character you want to delete : ";
            std::cin >> c;
            deleteChar(yourString, stringLength, c);
            std::cout << yourString << ".\n";
            system("pause");
            break;
        case 15:
            exitProgram(willExit);
            break;
        default:
            break;
        }
    } while (!willExit);
}

void exitProgram(bool& willExit) {
    willExit = 1;
}

void trimRight(char* yourString, int& stringLength) {
    for (int i = stringLength - 1; i >= 0; i--) {
        if (yourString[i] != ' ')
            break;
        else {
            yourString[i] = NULL;
            stringLength--;
        }
    }
}

void trimLeft(char* yourString, int& stringLength) {
    reverseString(yourString, stringLength);
    trimRight(yourString, stringLength);
    reverseString(yourString, stringLength);
}

void reverseString(char* yourString, int stringLength) {

    for (int i = 0; i < (int)stringLength / 2; i++) {
        swap(yourString[i], yourString[stringLength - i - 1]);

    }
}


void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void padRight(char* yourString, int& stringLength, int n) {
    if (stringLength < n) {
        while (stringLength < n) {
            yourString[stringLength++] = ' ';
        }
        yourString[stringLength] = NULL;
    }
}

void padLeft(char* yourString, int& stringLength, int n) {
    int diff = n - stringLength;
    if (diff > 0) {
        yourString[stringLength] = ' ';
        yourString[n] = NULL;

        for (int i = n - 1; i >= n - stringLength; i--)
            yourString[i] = yourString[i - diff];

        for (int i = 0; i < diff; i++)
            yourString[i] = ' ';

        stringLength = n;
    }
}

void center(char* yourString, int& stringLength) {
    int n;
    std::cout << "\nenter the least length of string: ";
    std::cin >> n;
    if (stringLength < n) {
        int nLeft = (n - stringLength) / 2;
        int nRight = n - nLeft - stringLength;
        padLeft(yourString, stringLength, nLeft + stringLength);
        padRight(yourString, stringLength, nRight + stringLength);
    }
}

bool isPalindrome(char* yourString, int stringLength) {
    bool isPalindrome_a = 1;

    for (int i = 0; i < stringLength / 2; i++) {
        if (yourString[i] != yourString[stringLength - 1 - i]) {
            isPalindrome_a = 0;
            break;
        }
    }
    return isPalindrome_a;
}

void truncate(char* yourString, int& stringLength, int n) {
    if (n < stringLength) {
        yourString[n] = NULL;
        stringLength = n;
    }
    std::cout << stringLength << std::endl;
}

void upperCharacter(char& a) {
    if (a >= 'a' && a <= 'z') {
        a = a - 32;
    }
}
void lowerCharacter(char& a) {
    if (a >= 'A' && a <= 'Z') {
        a = a + 32;
    }
}

void capitalizeWords(char* yourString, int stringLength) {
    upperCharacter(yourString[0]);
    for (int i = 1; i < stringLength; i++) {
        if (yourString[i - 1] == ' ')
            upperCharacter(yourString[i]);
        else
            lowerCharacter(yourString[i]);
    }
}

void capitalize(char* yourString, int stringLength) {
    for (int i = 0; i < stringLength; i++) {
        if (((yourString[i] >= 'a') && (yourString[i] <= 'z')) || ((yourString[i] >= 'A') && (yourString[i] <= 'Z'))) {
            upperCharacter(yourString[i]);
            break;
        }
   }
}
int length(char* yourString) {
    int i = 0;
    while (yourString[i] != NULL)
        i++;
    return i;
}

bool isAlpha(char* yourString, int stringLength) {
    bool temp = 1;
    for (int i = 0; i < stringLength; i++) {
        if (!((yourString[i] == ' ') || ((yourString[i] >= 'a') && (yourString[i] <= 'z')) || ((yourString[i] >= 'A') && (yourString[i] <= 'Z')) )) {
            temp = 0;
            break;
        }
    }
    return temp;
}

int count(char* yourString, char c, int stringLength) {
    int temp = 0;
    for (int i = 0; i < stringLength; i++) {
        if (yourString[i] == c) {
            temp++;
        }
    }
    return temp;
}

int count(char* yourString, int stringLength,char * secondString) {

    int stringLength2 = length(secondString);
    int temp = 0;
    for (int i = 0; i < stringLength2; i++) {
        temp += count(yourString, secondString[i], stringLength);
    }
    std::cout << "\nOccurrences of all charactes in second string in the first string : " << temp << std::endl;
    
    return temp;
}

void deleteChar(char* yourString, int &stringLength, char c) {
    for (int i = 0; i < stringLength; i++) {
        if (yourString[i] == c) {
            stringLength--;
            for (int j = i; j < stringLength; j++) {
                yourString[j] = yourString[j + 1];
            }
            yourString[stringLength] = NULL;
            i--;
        }
    }
}