#include "Pet.h"


double Pet::calculateMorniingRation()
{
    return 0;
}

double Pet::afternoonRation()
{
    return 0;
}

double Pet::untilHealthCheck()
{
    return 0;
}

int Pet::getID()
{
    return ID;
}

void Pet::setID(int ID)
{
    this->ID = ID;
}

int Pet::getType() 
{
    return type;
}

void Pet::setType(int type) 
{
    this->type = type;
}

double Pet::getWeight() 
{
    return weight;
}

void Pet::setWeight(double weight)
{
    this->weight = weight;
}

double Pet::getLength()
{
    return length;
}

void Pet::setLength(double length) 
{
    this->length = length;
}

double Pet::getHeight()
{
    return height;
}

void Pet::setHeight(double height) 
{
    this->height = height;
}

std::string Pet::getBreed()
{
    return breed;
}

void Pet::setBreed(std::string breed) 
{
    this->breed = breed;
}
std::string Pet::getHairColor() 
{
    return hairColor;
}

void Pet::setHairColor(std::string hairColor)
{
    this->hairColor = hairColor;
}

void Pet::inputDateFromString(std::string date)
{
    std::string day = date.substr(0, 2);
    recentHealthCheck.tm_mday = atoi(day.c_str());
    std::string month = date.substr(3, 2);
    recentHealthCheck.tm_mon = atoi(month.c_str()) - 1;
    std::string year = date.substr(6, 4);
    recentHealthCheck.tm_year = atoi(year.c_str()) - 1900;
}

void Pet::showPetRation() {

}

void Pet::showPetHealCheckInfo() {

}

std::string Pet::printDate(int day, int month, int year) {
    std::string temp = {};
    //print with format dd/mm/yy
    if ((day >= 0) && (day <= 9)) 
        temp = "0" + std::to_string(day) + "/";
    else 
        temp = std::to_string(day) + "/";

    if ((month >= 0) && (month <= 9)) 
        temp = temp + "0" + std::to_string(month) + "/";
    else 
        temp = temp + std::to_string(month) + "/";

    temp = temp + std::to_string(year);
    return temp;
}

tm Pet::nextHealthCheck(tm recentHealthCheck) {
    return recentHealthCheck;
}

void Pet::addPet()
{
    double weight;
    double length;
    double height;
    std::string breed;
    std::string hairColor;
    std::string recentHealthCheck;

    std::cout << "\nWeight (g): ";
    std::cin >> weight;
    setWeight(weight);
    std::cout << "Length (g) : ";
    std::cin >> length;
    setLength(length);
    std::cout << "Height (g) : ";
    std::cin >> height;
    setHeight(height);
    std::cout << "Breed : ";
    std::cin.ignore();
    getline(std::cin, breed);
    setBreed(breed);
    std::cout << "Hair color : ";
    getline(std::cin, hairColor);
    setHairColor(hairColor);
    std::cout << "Recent health check day (dd/mm/yyyy): ";
    getline(std::cin, recentHealthCheck);
    inputDateFromString(recentHealthCheck);
}

std::ostream& operator << (std::ostream& os, Pet* a_data)
{
    os << std::setw(3) << std::right;
    int n = a_data->getID();
    if (n < 10) {
        std::string ID;
        ID = "0" + std::to_string(n);
        os << ID;
    }
    else {
        std::string ID;
        ID = std::to_string(n);
        os << ID;
    }

    os << std::setw(7) << std::right;

    if (a_data->getType() == 1)
        os << "Dog";
    else if (a_data->getType() == 2)
        os << "Cat";

    os << std::setw(10) << std::right << a_data->getWeight()
        << std::setw(10) << std::right << a_data->getLength()
        << std::setw(10) << std::right << a_data->getHeight()
        << std::setw(25) << std::right << a_data->getBreed()
        << std::setw(25) << std::right << a_data->getHairColor();
    return os;
}

std::istream& operator >> (std::istream& is, Pet* a_data)
{
    //is >> (Pet*)a_data;
    is >> a_data->weight;
    is >> a_data->length;
    is >> a_data->height;
    is.ignore();
    getline(is, a_data->breed);
    getline(is, a_data->hairColor);
    return is;
}