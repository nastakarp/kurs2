//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "../../Util.h"
#include "Name.h"

// Конструктор
Name::Name(const char *last, const char *first, const char *patr, const char *dob) {
    int len = length(last);
    lastName = new char[len + 1];
    copy(last, lastName, len);

    len = length(first);
    firstName = new char[len + 1];
    copy(first, firstName, len);

    len = length(patr);
    patronymic = new char[len + 1];
    copy(patr, patronymic, len);

    len = length(dob);
    dateOfBirth = new char[len + 1];
    copy(dob, dateOfBirth, len);
}

// Деструктор
Name::~Name() {
    delete[] lastName;
    delete[] firstName;
    delete[] patronymic;
    delete[] dateOfBirth;
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Name &name) {
    os << name.firstName << " " << name.lastName << " " << name.patronymic << " " << name.dateOfBirth << " ";
    return os;
}

bool operator==(const Name &name1, const Name &name2) {
    return strcmp(name1.lastName, name2.lastName) == 0 &&
           strcmp(name1.firstName, name2.firstName) == 0 &&
           strcmp(name1.patronymic, name2.patronymic) == 0 &&
           strcmp(name1.dateOfBirth, name2.dateOfBirth) == 0;
}