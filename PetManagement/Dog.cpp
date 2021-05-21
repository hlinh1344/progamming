#include "Dog.h"

float Dog::morningRation() {
    return 0;
}

float Dog::afternoonRation() {
    return weight / 20.0 + length / 10.0;
}

float Dog::getHourOfPlayPerADay() {
    return hourOfPlayPerADay;
}
void Dog::setHourOfPlayPerADay(float hourOfPlayPerADay) {
    this->hourOfPlayPerADay = hourOfPlayPerADay;
}


void Dog::enterInfo(std::istream& is)
{
    std::string line;
    //Pet::enterInfo(is);
    is >> weight;
    is >> length;
    is >> height;
    is.ignore();
    getline(is, breed);
    getline(is, hairColor);
    is >> hourOfPlayPerADay;
    is.ignore();
    getline(is, line);
    Pet::inputDateFromString(line);
}

tm Dog::theNextHealthCheck(tm recentHealthCheck) {
    tm temp = recentHealthCheck;
    if ((temp.tm_mon + 6) > 11) {
        temp.tm_year++;
        temp.tm_mon = 5 - (11 - temp.tm_mon);
    }
    else
    {
        temp.tm_mon += 6;
    }
        
    return temp;
}

int Dog::untilTheHealthCheck(tm recentHealthCheck) {
    time_t currentTime = time(NULL);   // get time now
    tm now;
    localtime_s(&now, &currentTime);
    if (recentHealthCheck.tm_mon + 6 > 11) {
        recentHealthCheck.tm_year++;
        recentHealthCheck.tm_mon = 5 - (11 - recentHealthCheck.tm_mon);
    }
    else
        recentHealthCheck.tm_mon += 6;
    double  diff = (double) difftime(currentTime, mktime(&recentHealthCheck));
    diff = (-1)* (diff / 86400);
   // std::cout << round(diff) << " days until Health Check day."<< std::endl;
    return round(diff);
}

void Dog::petInfo(std::ostream& os) {
    os << std::setw(7) << std::right << "Dog"
        << std::setw(10) << std::right << weight
        << std::setw(10) << std::right << length
        << std::setw(10) << std::right << height
        << std::setw(25) << std::right << breed
        << std::setw(25) << std::right << hairColor << std::endl;
}

void Dog::showPetRation() {
   std::cout << std::setw(7) << std::right << "Dog"
        << std::setw(22) << std::right << Dog::morningRation() <<" g"
        << std::setw(22) << std::right << Dog::afternoonRation()<<" g" << std::endl;
}

void Dog::showPetHealCheckInfo() {
    tm nextHealthCheck = Dog::theNextHealthCheck(recentHealthCheck);
    std::cout << std::setw(7) << std::right << "Dog"
        << std::setw(30) << std::right 
        << Pet::printDate(recentHealthCheck.tm_mday,recentHealthCheck.tm_mon + 1,recentHealthCheck.tm_year + 1900)
        << std::setw(30) << std::right 
        << Pet::printDate(nextHealthCheck.tm_mday, nextHealthCheck.tm_mon + 1, nextHealthCheck.tm_year + 1900)
        << std::setw(25) << std::right << Dog::untilTheHealthCheck(recentHealthCheck) << std::endl;
}