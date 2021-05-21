#pragma once
#include "Pet.h"

class Cat : public Pet
{
private:
    float hourOfSleepPerADay;
public:
    void enterInfo(std::istream& is)  override;
    float morningRation() override;
    float afternoonRation() override;
    float getHourOfSleepPerADay();
    void setHourOfSleepPerADay(float hourOfSleepPerADay);
    int untilTheHealthCheck(tm recentHealthCheck) override;
    void petInfo(std::ostream& os)  override;
    void showPetHealCheckInfo() override;
    void showPetRation() override;
    tm theNextHealthCheck(tm recentHealthCheck) override;
};

