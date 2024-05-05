//
// Created by Анастасия on 05.05.2024.
//

#ifndef PROGA_KURS_YEARLIST_H
#define PROGA_KURS_YEARLIST_H

#include <iostream>
#include "../node/YearNode.h"

struct YearList {
    YearNode *head;
    YearNode *tail;

    YearList(); // Конструктор
    ~YearList(); // Деструктор

    friend std::ostream &operator<<(std::ostream &os, const YearList &list); // Оператор вывода узла в поток
    Year &appendNode(const int yearValue);
};

#endif //PROGA_KURS_YEARLIST_H
