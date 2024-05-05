//
// Created by Анастасия on 05.05.2024.
//

#ifndef PROGA_KURS_YEARNODE_H
#define PROGA_KURS_YEARNODE_H

#include <iostream>
#include "../core/Year.h" // Предполагается, что у вас есть заголовочный файл для класса Year

struct YearNode {
    Year data; // Данные узла
    YearNode *next; // Указатель на следующий узел

    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    YearNode(const Year value);

    // Деструктор для освобождения ресурсов
    ~YearNode();

    // Оператор сравнения равенства YearNode
    friend bool operator==(const YearNode &lhs, const YearNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const YearNode &node);
};
#endif //PROGA_KURS_YEARNODE_H
