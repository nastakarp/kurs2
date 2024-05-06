#ifndef PROGA_KURS_NAMENODE_H
#define PROGA_KURS_NAMENODE_H

#include <iostream>
#include "../core/Name.h"

struct NameNode {
    Name *data;
    NameNode *next; // Указатель на следующий узел

    // Конструктор для инициализации узла с заданным именем и указателем на следующий узел
    NameNode(Name *value);

    // Деструктор для освобождения ресурсов
    ~NameNode();

    // Оператор сравнения равенства NameNode
    friend bool operator==(const NameNode &lhs, const NameNode &rhs);

    friend std::ostream &operator<<(std::ostream &os, const NameNode &node);
};


#endif // PROGA_KURS_NAMENODE_H
