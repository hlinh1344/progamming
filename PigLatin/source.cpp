// pch.cpp: source file corresponding to the pre-compiled header
#include <iostream>
#include "pch.h"


// When you are using pre-compiled headers, this source file is necessary for compilation to succeed.
char* ToPigLatin(char* word) {
  
    char last[MAX] = {};
       
    char vowel[16] = "aeouiAEOUI";
    int mid = 0;

    int length = lengOfWord(word);
    int resultLength = length + 3;
    char *result = new char[resultLength];
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

    if (!isLowerCase(result[0])) {
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
    int i = 0;
    while (word[i] != NULL)
        i++;
    return i;
}


bool isVowel(char a, char vowel[]) {
    bool result = false;
    int n = lengOfWord(vowel);
    for (int i = 0; i < n; i++) {
        if (a == vowel[i]) {
            result = true;
            break;
        }
    }
    return result;
}

bool isLowerCase(char a) {
    if ((a >= 'a') && (a <= 'z')) 
        return false;
    return true;
}