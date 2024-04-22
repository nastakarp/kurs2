//
// Created by Анастасия on 23.04.2024.
//

#ifndef PROGA_KURS_POSITIONLIST_H
#define PROGA_KURS_POSITIONLIST_H

#include <iostream>
#include "../node/PositionNode.h"

struct PositionList {
    PositionNode *head; // Указатель на начало списка
    PositionNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    PositionList();

    // Деструктор для освобождения памяти
    ~PositionList();

    // Добавление узла в конец списка
    void appendNode(const Position value);

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const PositionList &list);
};

#endif //PROGA_KURS_POSITIONLIST_H
