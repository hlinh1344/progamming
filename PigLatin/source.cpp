// pch.cpp: source file corresponding to the pre-compiled header
#include <iostream>
#include "pch.h"


// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
char* ToPigLatin(char* word) {
  
    char last[MAX] = {};
    
    char vowel[] = { 'a','e','o','u','i','A','E','O','U','I' };
    char vowel[256] = "aeouiAEOUI";
    int mid = 0;

    int length = lengOfWord(word);

    char *result = new char(length);
    for (int i = 0; i < length; i++) {
        result[i] = word[i];
    }
    result[length] = NULL;
    


    if (isVowel(result[0], vowel)) {
        mid = 0;
    }
    else {
        for (int i = 1; i < length; i++) {
            if (isVowel(result[i], vowel) || (result[i] == 'y') || (result[i] == 'Y')) {
                mid = i;
                break;
            }
        }
    }

    if (!isLowerCaseCharacters(result[0])) {
        result[mid] -= 32;
        result[0] += 32;
    }

    int j = 0;
    for (; j < mid; j++) {
        last[j] = result[j];
    }

    int newLength = length;
    if (isVowel(result[0], vowel)) {
        last[j++] = 'w';
        last[j++] = 'a';
        last[j++] = 'y';
        newLength += 3;
    }
    else {
        last[j++] = 'a';
        last[j++] = 'y';
        newLength += 2;
    }

    int b = 0;
    for (int i = mid; i < length; i++) {
        result[b++] = result[i];
    }

    for (int i = 0; i < mid + (newLength - length); i++) {
        result[b++] = last[i];
    }
    result[b] = NULL;

    return result;
}



int lengOfWord(char* word) {
    //for (int i = 0; i < 43; i++) {
    //    if (word[i] == NULL) {
    //        return i;
    //    }
    //}
    // 
    // 
    // 
    // 
    // 
    // giai phong resource
    //return -1;
    int i = 0;
    for (; word[i] != NULL; i++)
        ;
    return i;

    int i = 0;
    while (word[i] != NULL)
        i++;
    return i;



    int temp = 0;
    while (word != NULL) {
        word++;
        temp++;
    }
    return temp;
}


bool isVowel(char a, char vowel[]) {
    bool result = false;
    int n = sizeof(vowel) / sizeof(char);
    for (int i = 0; i < n; i++) {
        if (a == vowel[i]) {
            result = true;
            break;
        }
    }
    return result;
}

bool isLowerCaseCharacters(char a) {
    if ((a >= 'a') && (a <= 'z')) 
        return 0;
    return 1;
}