//
// Created by Анастасия on 21.04.2024.
//

#ifndef PROGA_KURS_STATUSNODE_H
#define PROGA_KURS_STATUSNODE_H

#include <iostream>
#include "../core/Status.h" // Подключаем заголовочный файл для структуры Team, если необходимо

struct StatusNode {
    Status *data; // Данные узла
    StatusNode *next; // Указатель на следующий узел
    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    StatusNode(Status *value);

    // Деструктор для освобождения ресурсов
    ~StatusNode();

    // Оператор сравнения равенства NameNode
    friend bool operator==(const StatusNode &lhs, const StatusNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const StatusNode &node);


};

#endif //PROGA_KURS_STATUSNODE_H
