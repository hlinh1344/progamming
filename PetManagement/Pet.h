#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime> 
#include <math.h>


class Pet
{
public:
    int date=0;
    int month=0;
    int year=0;
    float weight=0;
    float length=0;
    float height=0;
    std::string breed = {};
    std::string hairColor = {};
    tm recentHealthCheck ;
   
public:
  
    virtual float calculateMorniingRation();
    virtual float afternoonRation();
    virtual int untilHealthCheck(tm recentHealthCheck);
    float getWeight();
    void setWeight(float weight);
    float getLength();
    void setLength(float length);
    float getHeight();
    void setHeight(float height);
    std::string getBreed();
    void setBreed(std::string breed);
    std::string getHairColor();
    void setHairColor(std::string hairColor);
    void inputDateFromString(std::string date);
    virtual void enterInfo(std::istream& is);
    virtual void showPetInfo(std::ostream& os);
    virtual void showPetRation();
    virtual void showPetHealCheckInfo();
    std::string printDate(int day, int month, int year);
    virtual tm nextHealthCheck(tm recentHealthCheck);
};


