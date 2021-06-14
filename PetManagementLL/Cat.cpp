#include "Cat.h"

double Cat::calculateMorniingRation() 
{
    return height * 5;
}

double Cat::afternoonRation() 
{
    return height * 5 + 15 - sleptHours;
}

double Cat::getSleptHours() 
{
    return sleptHours;
}

void Cat::setSleptHours(double sleptHours)
{
    this->sleptHours = sleptHours;
}

void Cat::enterInfo(std::istream& is, int &n)
{
    type = 2;
    Pet::enterInfo(is,n);
    std::string line;
    is >> sleptHours;
    is.ignore();
    getline(is, line);
    Pet::inputDateFromString(line);
}

tm Cat::nextHealthCheck(tm recentHealthCheck) 
{
    tm temp = recentHealthCheck;
    if (temp.tm_mon + 3 > 11)
    {
        temp.tm_year++;
        temp.tm_mon = 2 - (11 - temp.tm_mon);
    }
    else
        temp.tm_mon += 3;
    return temp;
}

double Cat::untilHealthCheck() 
{
    time_t currentTime = time(NULL);   // get time now
    tm now;
    localtime_s(&now, &currentTime);
    tm timeToHealthCheck = Cat::nextHealthCheck(recentHealthCheck);

    double  diff = (double)difftime(currentTime, mktime(&timeToHealthCheck));
    diff = -(1) * (diff / 86400);
    return round(diff);
}

void Cat::showPetRation()
{
    std::cout << std::setw(7) << std::right << "Cat"
        << std::setw(22) << std::right << Cat::calculateMorniingRation() << " g"
        << std::setw(22) << std::right << Cat::afternoonRation() << " g" << std::endl;
}

void Cat::showPetHealCheckInfo()
{
    tm nextHealthCheck = Cat::nextHealthCheck(recentHealthCheck);
    std::cout << std::setw(7) << std::right << "Cat"
        << std::setw(30) << std::right
        << Pet::printDate(recentHealthCheck.tm_mday, recentHealthCheck.tm_mon + 1, recentHealthCheck.tm_year + 1900)
        << std::setw(30) << std::right
        << Pet::printDate(nextHealthCheck.tm_mday, nextHealthCheck.tm_mon + 1, nextHealthCheck.tm_year + 1900)
        << std::setw(25) << std::right << Cat::untilHealthCheck() << std::endl;
}

void Cat::addPet() 
{
    type = 2;
    std::cout << "\nEnter information of a new cat :\n";
    Pet::addPet();
    double hour;
    std::cout << "Slept hours (h) : ";
    std::cin >> hour;
    Cat::setSleptHours(hour);
    std::cout << "\n\nA new cat has been added to the list!";
}