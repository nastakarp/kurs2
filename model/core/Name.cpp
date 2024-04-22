//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "../../Util.h"
#include "Name.h"

// Конструктор
Name::Name(const char *last, const char *first, const char *patr) {
    int len = length(last);
    lastName = new char[len + 1];
    copy(last, lastName, len);

    len = length(first);
    firstName = new char[len + 1];
    copy(first, firstName, len);

    len = length(patr);
    patronymic = new char[len + 1];
    copy(patr, patronymic, len);
}

// Деструктор
Name::~Name() {
    delete[] lastName;
    delete[] firstName;
    delete[] patronymic;
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Name &name) {
    os << name.firstName << " " << name.lastName << " " << name.patronymic << " ";
    return os;
}