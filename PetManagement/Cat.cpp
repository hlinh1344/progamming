#include "Cat.h"

float Cat::calculateMorniingRation() {
    return height * 5;
}

float Cat::afternoonRation() {
    return height * 5 + 15 - sleptHours;
}

float Cat::getSleptHours() {
    return sleptHours;
}

void Cat::setSleptHours(float sleptHours) {
    this->sleptHours = sleptHours;
}

void Cat::enterInfo(std::istream& is)
{
    Pet::enterInfo(is);
    std::string line;
    is >> sleptHours;
    is.ignore();
    getline(is, line);
    Pet::inputDateFromString(line);
}

tm Cat::nextHealthCheck(tm recentHealthCheck) {
    tm temp = recentHealthCheck;
    if (temp.tm_mon + 3 > 11) {
        temp.tm_year++;
        temp.tm_mon = 2 - (11 - temp.tm_mon);
    }
    else
        temp.tm_mon += 3;
    return temp;
}


int Cat::untilHealthCheck(tm recentHealthCheck) {
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
        << std::setw(22) << std::right << Cat::calculateMorniingRation() << " g"
        << std::setw(22) << std::right << Cat::afternoonRation() << " g" << std::endl;
}
void Cat::showPetInfo(std::ostream& os) {
    os << std::setw(7) << std::right << "Cat";
    Pet::showPetInfo(os);
}


void Cat::showPetHealCheckInfo() {
    tm nextHealthCheck = Cat::nextHealthCheck(recentHealthCheck);
    std::cout << std::setw(7) << std::right << "Cat"
        << std::setw(30) << std::right
        << Pet::printDate(recentHealthCheck.tm_mday, recentHealthCheck.tm_mon + 1, recentHealthCheck.tm_year + 1900)
        << std::setw(30) << std::right
        << Pet::printDate(nextHealthCheck.tm_mday, nextHealthCheck.tm_mon + 1, nextHealthCheck.tm_year + 1900)
        << std::setw(25) << std::right << Cat::untilHealthCheck(recentHealthCheck) << std::endl;
}
