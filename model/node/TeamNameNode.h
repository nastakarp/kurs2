//
// Created by Анастасия on 21.04.2024.
//

#ifndef PROGA_KURS_TEAMNAMENODE_H
#define PROGA_KURS_TEAMNAMENODE_H

#include "../core/TeamName.h" // Подключаем заголовочный файл для структуры TeamName

struct TeamNameNode {
    TeamName data;
    TeamNameNode* next;

    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    TeamNameNode(const TeamName value);

    // Деструктор для освобождения ресурсов
    ~TeamNameNode();
};

// Оператор сравнения равенства NameNode
bool operator==(const TeamNameNode &lhs, const TeamNameNode &rhs);

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const TeamNameNode &node);


#endif //PROGA_KURS_TEAMNAMENODE_H
