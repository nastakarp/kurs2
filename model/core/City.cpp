//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "../../Util.h"
#include "City.h"

// Определение конструктора
City::City(const char *cityName) {
    int len = length(cityName);
    this->city = new char[len + 1];
    copy(cityName, this->city, len);
}

// Определение деструктора
City::~City() {
    delete[] city;
}
// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const City &city) {
    os << city.city << " ";
    return os;
}

bool operator==(const City &city1, const City &city2) {
    return strcmp(city1.city, city2.city) == 0;
}