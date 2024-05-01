//
// Created by Анастасия on 22.04.2024.
//

#ifndef PROGA_KURS_NAMELIST_H
#define PROGA_KURS_NAMELIST_H

#include "../node/NameNode.h"

using namespace std;

// Определение класса для списка узлов
struct NameList {
    NameNode *head{}; // Указатель на начало списка
    NameNode *tail{}; // Указатель на конец списка
    // Конструктор по умолчанию
    NameList();

    // Деструктор для освобождения памяти
    ~NameList();

    // Добавление узла в конец списка
    Name &appendNode(const Name &value);

    // Вывод StringList в поток
    friend std::ostream &operator<<(std::ostream &os, const NameList &node);
};

#endif //PROGA_KURS_NAMELIST_H
