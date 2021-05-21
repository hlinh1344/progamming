#pragma once
#include "Pet.h"

class Dog :public Pet
{
private:
    float hourOfPlayPerADay;
public:
    void enterInfo(std::istream& is) override;    
    float morningRation() override;
    float afternoonRation() override;
    float getHourOfPlayPerADay();
    void setHourOfPlayPerADay(float hourOfPlayPerADay);
    int untilTheHealthCheck(tm recentHealthCheck) override;
    void petInfo(std::ostream& os) override;
    void showPetRation() override;
    void showPetHealCheckInfo() override;
    tm theNextHealthCheck(tm recentHealthCheck) override;
};

