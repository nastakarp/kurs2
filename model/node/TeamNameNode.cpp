//
// Created by Анастасия on 06.05.2024.
//

#include "TeamNameNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
TeamNameNode::TeamNameNode(const TeamName value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
TeamNameNode::~TeamNameNode() {
    // Поскольку data - объект типа TeamName, его деструктор будет вызван автоматически при удалении TeamNameNode
}

// Оператор сравнения равенства TeamNameNode
bool operator==(const TeamNameNode &lhs, const TeamNameNode &rhs) {
    // Сравниваем данные имен команд
    return lhs.data == rhs.data;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const TeamNameNode &node) {
    os << node.data;
    return os;
}
