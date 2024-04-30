//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "../../Util.h"
#include "Position.h"


// Определение конструктора
Position::Position(const char *playerPosition) {
    int len = length(playerPosition);
    position = new char[len + 1];
    copy(playerPosition, position, len);
}
// Определение деструктора
Position::~Position() {
    delete[] position;
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Position &position) {
    os << position.position << " ";
    return os;
}
bool operator==(const Position &position1, const Position &position2) {
    return strcmp(position1.position, position2.position) == 0;
}