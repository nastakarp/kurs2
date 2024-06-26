//
// Created by Анастасия on 18.04.2024.
//

#ifndef PROGA_KURS_NAME_H
#define PROGA_KURS_NAME_H

#include <iostream>
#include "../../Util.h"

struct Name {
    // Конструктор
    Name(const char *name, const char *dob);

    // Деструктор
    ~Name();

    char *fullname;

    char *dateOfBirth; // Дата рождения

    friend std::ostream &operator<<(std::ostream &os, const Name &name);

    friend bool operator==(const Name &name1, const Name &name2);
};

#endif //PROGA_KURS_NAME_H
