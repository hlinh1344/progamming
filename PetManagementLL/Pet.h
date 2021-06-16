#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime> 
#include <math.h>


class Pet
{
protected:
    int ID;
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
    int getID();
    void setID(int ID);
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
    virtual void showPetRation();
    virtual void showPetHealCheckInfo();
    std::string printDate(int day, int month, int year);
    virtual tm nextHealthCheck(tm recentHealthCheck);
    virtual void addPet();
    friend std::ostream& operator << (std::ostream& os, Pet* a_data);
    friend std::istream& operator >> (std::istream& is, Pet* a_data);
};


