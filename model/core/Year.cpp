//
// Created by Анастасия on 05.05.2024.
//

#include "Year.h"
// Определение конструктора
Year::Year(int yearValue) : value(yearValue) {}

// Определение деструктора (если не требуется освобождение памяти, его можно опустить)
Year::~Year() {}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Year &year) {
    os << year.value << " ";
    return os;
}

// Оператор сравнения для проверки равенства годов
bool operator==(const Year &year1, const Year &year2) {
    return year1.value == year2.value;
}
