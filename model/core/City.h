//
// Created by Анастасия on 20.04.2024.
//

#ifndef PROGA_KURS_CITY_H
#define PROGA_KURS_CITY_H


#include <iostream>

struct City {
    char *city;

    // Конструктор
    City(const char *cityName);

    // Деструктор
    ~City();
    friend std::ostream &operator<<(std::ostream &os, const City &city);
};


#endif //PROGA_KURS_CITY_H
