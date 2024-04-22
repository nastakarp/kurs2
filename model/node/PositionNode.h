//
// Created by Анастасия on 20.04.2024.
//

#ifndef PROGA_KURS_POSITIONNODE_H
#define PROGA_KURS_POSITIONNODE_H


#include <iostream>
#include "../core/Position.h"

struct PositionNode {
    Position data; // Исправлено на Position
    PositionNode *next; // Указатель на следующий узел

    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    explicit PositionNode(const Position value);

    // Деструктор для освобождения ресурсов
    ~PositionNode();

    // Оператор сравнения равенства PositionNode
    friend bool operator==(const PositionNode &lhs, const PositionNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const PositionNode &node);
};

#endif //PROGA_KURS_POSITIONNODE_H
