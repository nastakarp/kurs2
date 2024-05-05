//
// Created by Анастасия on 05.05.2024.
//

#ifndef PROGA_KURS_YEAR_H
#define PROGA_KURS_YEAR_H

#include <iostream>

struct Year {
    int value;

    // Конструктор
    Year(int yearValue);

    // Деструктор (можно опустить, если он не нужен)
    ~Year();

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const Year &year);

    // Оператор сравнения для проверки равенства годов
    friend bool operator==(const Year &year1, const Year &year2);
};

#endif //PROGA_KURS_YEAR_H
