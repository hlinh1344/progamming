#include "Cat.h"

float Cat::morningRation() {
    return height * 5;
}

float Cat::afternoonRation() {
    return height * 5 + 15 - hourOfSleepPerADay;
}

float Cat::getHourOfSleepPerADay() {
    return hourOfSleepPerADay;
}
void Cat::setHourOfSleepPerADay(float hourOfSleepPerADay) {
    this->hourOfSleepPerADay = hourOfSleepPerADay;
}
void Cat::enterInfo(std::istream& is)
{
    std::string line;
    //Pet::enterInfo(is);
    is >> weight;
    is >> length;
    is >> height;
    is.ignore();
    getline(is, breed);
    getline(is, hairColor);
    is >> hourOfSleepPerADay;
    is.ignore();
    getline(is, line);
    Pet::inputDateFromString(line);
}

tm Cat::theNextHealthCheck(tm recentHealthCheck) {
    tm temp = recentHealthCheck;
    if (temp.tm_mon + 3 > 11) {
        temp.tm_year++;
        temp.tm_mon = 2 - (11 - temp.tm_mon);
    }
    else
        temp.tm_mon += 3;
    return temp;
}


int Cat::untilTheHealthCheck(tm recentHealthCheck) {
    time_t currentTime = time(NULL);   // get time now
    tm now;
    localtime_s(&now, &currentTime);
    if (recentHealthCheck.tm_mon + 3 > 11) {
        recentHealthCheck.tm_year++;
        recentHealthCheck.tm_mon = 2 - (11 - recentHealthCheck.tm_mon);
    }
    else
        recentHealthCheck.tm_mon += 3;
    double  diff = (double)difftime(currentTime, mktime(&recentHealthCheck));
    diff = -(1)*(diff / 86400);
    
    return round(diff);
}
void Cat::showPetRation() {
    std::cout << std::setw(7) << std::right << "Cat"
        << std::setw(22) << std::right << Cat::morningRation() << " g"
        << std::setw(22) << std::right << Cat::afternoonRation() << " g" << std::endl;
}
void Cat::petInfo(std::ostream& os) {
    os << std::setw(7) << std::right << "Cat"
        << std::setw(10) << std::right << weight
        << std::setw(10) << std::right << length
        << std::setw(10) << std::right << height
        << std::setw(25) << std::right << breed
        << std::setw(25) << std::right << hairColor << std::endl;
}


void Cat::showPetHealCheckInfo() {
    tm nextHealthCheck = Cat::theNextHealthCheck(recentHealthCheck);
    std::cout << std::setw(7) << std::right << "Cat"
        << std::setw(30) << std::right
        << Pet::printDate(recentHealthCheck.tm_mday, recentHealthCheck.tm_mon + 1, recentHealthCheck.tm_year + 1900)
        << std::setw(30) << std::right
        << Pet::printDate(nextHealthCheck.tm_mday, nextHealthCheck.tm_mon + 1, nextHealthCheck.tm_year + 1900)
        << std::setw(25) << std::right << Cat::untilTheHealthCheck(recentHealthCheck) << std::endl;
}
