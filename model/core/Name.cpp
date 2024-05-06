//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "../../Util.h"
#include "Name.h"

// Конструктор
Name::Name(const char *name, const char *dob) {
    int len = length(name);
    fullname = new char[len + 1];
    copy(name, fullname, len);

    len = length(dob);
    dateOfBirth = new char[len + 1];
    copy(dob, dateOfBirth, len);
}

// Деструктор
Name::~Name() {
    delete[] fullname;
    delete[] dateOfBirth;
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Name &name) {
    os << name.fullname << " " << name.dateOfBirth << " ";
    return os;
}

bool operator==(const Name &name1, const Name &name2) {
    return strcmp(name1.fullname, name2.fullname) == 0  &&
           strcmp(name1.dateOfBirth, name2.dateOfBirth) == 0;
}
