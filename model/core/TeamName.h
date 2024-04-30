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

    friend std::ostream &operator<<(std::ostream &os, const TeamName &name);

    friend bool operator==(const TeamName &name1, const TeamName &name2);
};


#endif //PROGA_KURS_TEAMNAME_H
