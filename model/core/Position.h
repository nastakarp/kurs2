//
// Created by Анастасия on 20.04.2024.
//

#ifndef PROGA_KURS_POSITION_H
#define PROGA_KURS_POSITION_H

#include <iostream>

struct Position {
    const char *position;

    // Конструктор
    Position(const char *playerPosition);

    // Деструктор
    ~Position();

    friend std::ostream &operator<<(std::ostream &os, const Position &position);
};

#endif //PROGA_KURS_POSITION_H
