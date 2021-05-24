#pragma once
#include "Pet.h"

class Cat : public Pet
{
private:
    float sleptHours;
public:
    void enterInfo(std::istream& is)  override;
    float calculateMorniingRation() override;
    float afternoonRation() override;
    float getSleptHours();
    void setSleptHours(float sleptHours);
    int untilHealthCheck(tm recentHealthCheck) override;
    void showPetInfo(std::ostream& os)  override;
    void showPetHealCheckInfo() override;
    void showPetRation() override;
    tm nextHealthCheck(tm recentHealthCheck) override;
};

