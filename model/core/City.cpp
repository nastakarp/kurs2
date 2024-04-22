//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "../../Util.h"
#include "City.h"

// Определение конструктора
City::City(const char* cityName) {
    int len = length(cityName);
    city = new char[len + 1];
    copy(cityName, city, len);
}

// Определение деструктора
City::~City() {
    delete[] city;
}
