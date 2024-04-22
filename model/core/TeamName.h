//
// Created by Анастасия on 21.04.2024.
//

#ifndef PROGA_KURS_TEAMNAME_H
#define PROGA_KURS_TEAMNAME_H

#include "../../Util.h" // Включаем заголовочный файл с определениями функций length(), copy() и cleanup()
#include <iostream> // Для использования объекта потока std::cout

struct TeamName {
    char *name;

    // Конструктор
    TeamName(const char *cmd);

    // Деструктор
    ~TeamName();
};


#endif //PROGA_KURS_TEAMNAME_H
