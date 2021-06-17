#pragma once
#include "Pet.h"

class Dog :public Pet
{
private:
    double playedHours;
public:
    double calculateMorniingRation() override;
    double afternoonRation() override;
    double getPlayedHours();
    void setPlayedHours(double playedHours);
    double untilHealthCheck() override;
    void showPetRation() override;
    void showPetHealCheckInfo() override;
    tm nextHealthCheck(tm recentHealthCheck) override;
    void addPet() override;
    friend std::istream& operator >> (std::istream& is, Dog* a_data);
};

