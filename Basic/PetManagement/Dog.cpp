#include "Dog.h"

float Dog::calculateMorniingRation() {
    return 0;
}

float Dog::afternoonRation() {
    return weight / 20.0 + length / 10.0;
}

float Dog::getPlayedHours() {
    return playedHours;
}
void Dog::setPlayedHours(float playedHours) {
    this->playedHours = playedHours;
}


void Dog::enterInfo(std::istream& is)
{
    Pet::enterInfo(is);
    std::string line;
    is >> playedHours;
    is.ignore();
    getline(is, line);
    Pet::inputDateFromString(line);
}

tm Dog::nextHealthCheck(tm recentHealthCheck) {
    tm temp = recentHealthCheck;
    if ((temp.tm_mon + 6) > 11) {
        temp.tm_year++;
        temp.tm_mon = 5 - (11 - temp.tm_mon);
    }
    else
        temp.tm_mon += 6;
    return temp;
}

double Dog::untilHealthCheck() {
    time_t currentTime = time(NULL);   // get time now
    tm now;
    localtime_s(&now, &currentTime);
    tm timeToHealthCheck = Dog::nextHealthCheck(recentHealthCheck);
    double  diff = (double)difftime(currentTime, mktime(&timeToHealthCheck));
    diff = -(1) * (diff / 86400);
    return round(diff);
}

void Dog::showPetInfo(std::ostream& os) {
    os << std::setw(7) << std::right << "Dog";
    Pet::showPetInfo(os);
}

void Dog::showPetRation() {
   std::cout << std::setw(7) << std::right << "Dog"
        << std::setw(22) << std::right << Dog::calculateMorniingRation() <<" g"
        << std::setw(22) << std::right << Dog::afternoonRation()<<" g" << std::endl;
}

void Dog::showPetHealCheckInfo() {
    tm nextHealthCheck = Dog::nextHealthCheck(recentHealthCheck);
    std::cout << std::setw(7) << std::right << "Dog"
        << std::setw(30) << std::right 
        << Pet::printDate(recentHealthCheck.tm_mday,recentHealthCheck.tm_mon + 1,recentHealthCheck.tm_year + 1900)
        << std::setw(30) << std::right 
        << Pet::printDate(nextHealthCheck.tm_mday, nextHealthCheck.tm_mon + 1, nextHealthCheck.tm_year + 1900)
        << std::setw(25) << std::right << Dog::untilHealthCheck() << std::endl;
}