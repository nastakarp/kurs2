//
// Created by Анастасия on 07.05.2024.
//

#ifndef PROGA_KURS_TEAMNODE_H
#define PROGA_KURS_TEAMNODE_H

#include <iostream>
#include "../core/Team.h"

struct TeamNode {
    Team *data; // Данные узла
    TeamNode *next; // Указатель на следующий узел

    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    TeamNode(Team *value);

    // Деструктор для освобождения ресурсов
    ~TeamNode();

    // Оператор сравнения равенства TeamNode
    friend bool operator==(const TeamNode &lhs, const TeamNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const TeamNode &node);
};

#endif //PROGA_KURS_TEAMNODE_H
