//
// Created by Анастасия on 07.05.2024.
//

#ifndef PROGA_KURS_TEAMLIST_H
#define PROGA_KURS_TEAMLIST_H

#include <iostream>
#include "../node/TeamNode.h"

struct TeamList {
    TeamNode *head; // Указатель на начало списка
    TeamNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    TeamList();

    // Деструктор для освобождения памяти
    ~TeamList();

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const TeamList &list);

    TeamNode * appendNode(Team *value);
};
#endif //PROGA_KURS_TEAMLIST_H
