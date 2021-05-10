// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.
#pragma once

#include "framework.h"
#ifndef STRING3DLL_EXPORTS
    #define STRING3DLL_API __declspec(dllexport)
#else
    #define STRING3DLL_API __declspec(dllimport)

// add headers that you want to pre-compile here


#endif 

STRING3DLL_API int length(char* yourString);
STRING3DLL_API void menu(int& select, bool willExit, char* yourString, int& stringLength);
STRING3DLL_API void exitProgram(bool& willExit);
STRING3DLL_API void trimRight(char* yourString, int& stringLength);
STRING3DLL_API void trimLeft(char* yourString, int& stringLength);
STRING3DLL_API void reverseString(char* yourString, int stringLength);
STRING3DLL_API void swap(char& a, char& b);
STRING3DLL_API void padRight(char* yourString, int& stringLength, int n);
STRING3DLL_API void padLeft(char* yourString, int& stringLength, int n);
STRING3DLL_API void center(char* yourString, int& stringLength);
STRING3DLL_API bool isPalindrome(char* yourString, int stringLength);
STRING3DLL_API void truncate(char* yourString, int& lengOfString, int n);
STRING3DLL_API void upperCharacter(char& a);
STRING3DLL_API void lowerCharacter(char& a);
STRING3DLL_API void capitalizeWords(char* yourString, int stringLength);
STRING3DLL_API bool isAlpha(char* yourString, int stringLength);
STRING3DLL_API void capitalize(char* yourString, int stringLength);
STRING3DLL_API int count(char *yourString, char c, int stringLength);
STRING3DLL_API int count(char* yourString, int stringLength, char * secondString);
STRING3DLL_API void deleteChar(char* yourString, int& stringLength, char c);