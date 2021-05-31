#include "Pet.h"


float Pet:: calculateMorniingRation()
{
    return 0;
}

float Pet::afternoonRation()
{
    return 0;
}

double Pet::untilHealthCheck()
{
    return 0;
}

float Pet::getWeight() {
    return weight;
}

void Pet::setWeight(float weight) {
    this->weight = weight;
}

float Pet::getLength() {
    return length;
}

void Pet::setLength(float length) {
    this->length = length;
}

float Pet::getHeight() {
    return height;
}

void Pet::setHeight(float height) {
    this->height = height;
}

std::string Pet::getBreed() {
    return breed;
}

void Pet::setBreed(std::string breed) {
    this->breed = breed;
}
std::string Pet::getHairColor() {
    return hairColor;
}

void Pet::setHairColor(std::string hairColor) {
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


 void Pet::showPetInfo(std::ostream& os) {
     os  << std::setw(10) << std::right << weight
         << std::setw(10) << std::right << length
         << std::setw(10) << std::right << height
         << std::setw(25) << std::right << breed
         << std::setw(25) << std::right << hairColor << std::endl;
}

void Pet::enterInfo(std::istream& is)
{
    is >> weight;
    is >> length;
    is >> height;
    is.ignore();
    getline(is, breed);
    getline(is, hairColor);
}

void Pet::showPetRation() {

}

 void Pet::showPetHealCheckInfo() {

 }


 std::string Pet::printDate(int day, int month, int year) {
     std::string temp = {};
     //print with format dd/mm/yy
     if ((day >= 0) && (day <= 9)) {
         temp = "0" + std::to_string(day) + "/";
     }

     else {
         temp = std::to_string(day) + "/";
     }
       
     if ((month >= 0) && (month <= 9)) {
         temp = temp + "0" + std::to_string(month) + "/";
     }
     else {
         temp = temp + std::to_string(month) + "/";
     }
      
     temp = temp + std::to_string(year);
     return temp;
 }

 tm Pet::nextHealthCheck(tm recentHealthCheck) {
     return recentHealthCheck;
 }

