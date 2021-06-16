#pragma once
#include "Pet.h"

class Cat : public Pet
{
private:
    double sleptHours;
public:
    double calculateMorniingRation() override;
    double afternoonRation() override;
    double getSleptHours();
    void setSleptHours(double sleptHours);
    double untilHealthCheck() override;
    void showPetHealCheckInfo() override;
    void showPetRation() override;
    tm nextHealthCheck(tm recentHealthCheck) override;
    void addPet() override;
    friend std::istream& operator >> (std::istream& is, Cat* a_data);
};

