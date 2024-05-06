//
// Created by Анастасия on 06.05.2024.
//

#ifndef PROGA_KURS_TEAMNAMENODE_H
#define PROGA_KURS_TEAMNAMENODE_H
#include <iostream>
#include "../core/TeamName.h" // Подключаем заголовочный файл для структуры TeamName, если необходимо

struct TeamNameNode {
    TeamName data; // Данные узла
    TeamNameNode *next; // Указатель на следующий узел

    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    TeamNameNode(const TeamName value);

    // Деструктор для освобождения ресурсов
    ~TeamNameNode();

    // Оператор сравнения равенства TeamNameNode
    friend bool operator==(const TeamNameNode &lhs, const TeamNameNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const TeamNameNode &node);
};

#endif //PROGA_KURS_TEAMNAMENODE_H
