#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime> 
#include <math.h>


class Pet
{
protected:
    int type;
    double weight;
    double length;
    double height;
    std::string breed;
    std::string hairColor;
    tm recentHealthCheck;
public:
    virtual double calculateMorniingRation();
    virtual double afternoonRation();
    virtual double untilHealthCheck();
    int getType();
    void setType(int type);
    double getWeight();
    void setWeight(double weight);
    double getLength();
    void setLength(double length);
    double getHeight();
    void setHeight(double height);
    std::string getBreed();
    void setBreed(std::string breed);
    std::string getHairColor();
    void setHairColor(std::string hairColor);
    void inputDateFromString(std::string date);
    virtual void enterInfo(std::istream& is);
    virtual void showPetRation();
    virtual void showPetHealCheckInfo();
    std::string printDate(int day, int month, int year);
    virtual tm nextHealthCheck(tm recentHealthCheck);
    virtual void addPet();
};


