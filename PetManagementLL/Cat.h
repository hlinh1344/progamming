#pragma once
#include "Pet.h"

class Cat : public Pet
{
private:
    double sleptHours;
public:
    void enterInfo(std::istream& is)  override;
    double calculateMorniingRation() override;
    double afternoonRation() override;
    double getSleptHours();
    void setSleptHours(double sleptHours);
    double untilHealthCheck() override;
    void showPetHealCheckInfo() override;
    void showPetRation() override;
    tm nextHealthCheck(tm recentHealthCheck) override;
    void addPet() override;
};

