//
// Created by Анастасия on 06.05.2024.
//

#ifndef PROGA_KURS_TEAMNAMELIST_H
#define PROGA_KURS_TEAMNAMELIST_H
#include <iostream>
#include "../node/TeamNameNode.h"

struct TeamNameList {
    TeamNameNode *head; // Указатель на начало списка
    TeamNameNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    TeamNameList();

    // Деструктор для освобождения памяти
    ~TeamNameList();

    // Добавление узла в конец списка
    TeamName &appendNode(const TeamName value);

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const TeamNameList &list);
};

#endif //PROGA_KURS_TEAMNAMELIST_H
