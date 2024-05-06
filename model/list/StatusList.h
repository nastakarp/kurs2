//
// Created by Анастасия on 23.04.2024.
//

#ifndef PROGA_KURS_STATUSLIST_H
#define PROGA_KURS_STATUSLIST_H

#include <iostream>
#include "../node/StatusNode.h"

struct StatusList {
    StatusNode *head; // Указатель на начало списка
    StatusNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    StatusList();

    // Деструктор для освобождения памяти
    ~StatusList();

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const StatusList &list);

    StatusNode *appendNode(Status *value);
};

#endif //PROGA_KURS_STATUSLIST_H
