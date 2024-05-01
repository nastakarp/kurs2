//
// Created by Анастасия on 23.04.2024.
//

#ifndef PROGA_KURS_CITYLIST_H
#define PROGA_KURS_CITYLIST_H

#include <iostream>
#include "../node/CityNode.h"

struct CityList {
    CityNode *head; // Указатель на начало списка
    CityNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    CityList();

    // Деструктор для освобождения памяти
    ~CityList();

    // Добавление узла в конец списка
    City &appendNode(const City value);

    // Оператор вывода узла в поток
    friend std::ostream &operator<<(std::ostream &os, const CityList &list);
};

#endif //PROGA_KURS_CITYLIST_H
