#pragma once
#include "Pet.h"

class Dog :public Pet
{
private:
    float playedHours;
public:
    void enterInfo(std::istream& is) override;    
    float calculateMorniingRation() override;
    float afternoonRation() override;
    float getPlayedHours();
    void setPlayedHours(float playedHours);
    int untilHealthCheck(tm recentHealthCheck) override;
    void showPetInfo(std::ostream& os) override;
    void showPetRation() override;
    void showPetHealCheckInfo() override;
    tm nextHealthCheck(tm recentHealthCheck) override;
};

