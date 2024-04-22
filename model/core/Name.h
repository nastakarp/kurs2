//
// Created by Анастасия on 18.04.2024.
//

#ifndef PROGA_KURS_NAME_H
#define PROGA_KURS_NAME_H

#include <iostream>
#include "../../Util.h"

struct Name {
    // Конструктор
    Name(const char* last, const char* first, const char* patr);

    // Деструктор
    ~Name();

    char* lastName;
    char* firstName;
    char* patronymic;

    friend std::ostream& operator<<(std::ostream& os, const Name& name);
};

#endif //PROGA_KURS_NAME_H
