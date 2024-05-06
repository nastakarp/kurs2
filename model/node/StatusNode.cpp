//
// Created by Анастасия on 21.04.2024.
//

#include "StatusNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
StatusNode::StatusNode(Status *value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
StatusNode::~StatusNode() = default;

// Оператор сравнения равенства NameNode
bool operator==(const StatusNode &lhs, const StatusNode &rhs) {
    // Сравниваем данные игроков
    return lhs.data== rhs.data;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const StatusNode &node) {
    os << node.data;
    return os;
}
