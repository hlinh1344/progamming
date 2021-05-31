#pragma once
#include "Pet.h"

class Dog :public Pet
{
private:
    double playedHours;
public:
    void enterInfo(std::istream& is) override;
    double calculateMorniingRation() override;
    double afternoonRation() override;
    double getPlayedHours();
    void setPlayedHours(double playedHours);
    double untilHealthCheck() override;
    void showPetInfo(std::ostream& os) override;
    void showPetRation() override;
    void showPetHealCheckInfo() override;
    tm nextHealthCheck(tm recentHealthCheck) override;
    void addPet() override;

};

