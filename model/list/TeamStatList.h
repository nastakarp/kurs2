//
// Created by Анастасия on 23.04.2024.
//

#ifndef PROGA_KURS_TEAMSTATLIST_H
#define PROGA_KURS_TEAMSTATLIST_H

#include <iostream>
#include "../node/TeamStatNode.h"

struct TeamStatList {
    TeamStatNode *head; // Указатель на начало списка
    TeamStatNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    TeamStatList();

    // Деструктор для освобождения памяти
    ~TeamStatList();

    // Добавление узла в конец списка
    TeamStat &appendNode(const TeamStat value);

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const TeamStatList &list);
};

#endif //PROGA_KURS_TEAMSTATLIST_H
