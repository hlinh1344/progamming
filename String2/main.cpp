#include <iostream>
#include <cstring>
#include "pch.h"
using namespace std;

//char* ToPigLatin(char* word);
//int lengOfWord(char* word);
//bool isVowel(char a, char vowel[]);
//bool isLowerCaseCharacters(char a);

int main()
{


    char word[5][MAX];
    word[0];
    word[0][1];

    int i;				
  
    cout << "Input 5 words: ";
    for (i = 0; i < 5; i++)
        cin >> word[i];

    cout << "\nPig Latin version of the 5 words:\n";
    for (i = 0; i < 5; i++)
    {
        ToPigLatin(word[i]);
        cout << word[i] << ' ';
    }

    cout << "\n";



    cout << "\n";
    system("pause");
    return 0;
}


//char* ToPigLatin(char* word) {
//  
//    char last[MAX] = {};
//    char vowel[] = { 'a','e','o','u','i','A','E','O','U','I' };
//    int mid = 0;
//
//    int length = lengOfWord(word);
//
//
//
//
//    if (isVowel(word[0], vowel)) {
//        mid = 0;
//    }
//    else {
//        for (int i = 1; i < length; i++) {
//            if (isVowel(word[i], vowel) || (word[i] == 'y') || (word[i] == 'Y')) {
//                mid = i;
//                break;
//            }
//        }
//    }
//
//    if (!isLowerCaseCharacters(word[0])) {
//        word[mid] -= 32;
//        word[0] += 32;
//    }
//
//    int j = 0;
//    for (; j < mid; j++) {
//        last[j] = word[j];
//    }
//
//
//    int newLength = length;
//    if (isVowel(word[0], vowel)) {
//        last[j++] = 'w';
//        last[j++] = 'a';
//        last[j++] = 'y';
//        newLength += 3;
//    }
//    else {
//        last[j++] = 'a';
//        last[j++] = 'y';
//        newLength += 2;
//    }
//
//
//    int b = 0;
//    for (int i = mid; i < length; i++) {
//        word[b++] = word[i];
//    }
//
//    for (int i = 0; i < mid + (newLength - length); i++) {
//        word[b++] = last[i];
//    }
//    word[b] = NULL;
//
//    return word;
//}
//
//
//
//int lengOfWord(char* word) {
//    for (int i = 0; i < 43; i++) {
//        if (word[i] == NULL) {
//            return i;
//        }
//    }
//}
//
//bool isVowel(char a, char vowel[]) {
//    for (int i = 0; i < 10; i++) {
//        if (a == vowel[i]) {
//            return 1;
//        }
//    }
//    return 0;
//}
//
//bool isLowerCaseCharacters(char a) {
//    if ((a >= 65) && (a <= 90)) {
//        return 0;
//    }
//    return 1;
//}