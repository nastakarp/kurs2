//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "Position.h"

// Определение конструктора
Position::Position(const char *playerPosition) : position(playerPosition) {}

// Определение деструктора
Position::~Position() {
    // Здесь не требуется дополнительных действий для деструктора
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Position &position) {
    os << position.position << " ";
    return os;
}