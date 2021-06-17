#pragma once

#include "framework.h"
const int MAX = 43;
#ifdef PIGLATIN_EXPORTS
    #define PIGLATIN_API __declspec(dllexport)
#else
    #define PIGLATIN_API __declspec(dllimport)
#endif

PIGLATIN_API char* ToPigLatin(char* word);
PIGLATIN_API int lengOfWord(char* word);
PIGLATIN_API bool isVowel(char a, char vowel[]);
PIGLATIN_API bool isLowerCase(char a);


