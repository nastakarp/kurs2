//
// Created by Анастасия on 20.04.2024.
//

#include "PositionNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
PositionNode::PositionNode(Position *value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
PositionNode::~PositionNode() = default;

// Оператор сравнения равенства NameNode
bool operator==(const PositionNode &lhs, const PositionNode &rhs) {
    // Сравниваем данные игроков
    return rhs.data == lhs.data;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const PositionNode &node) {
    os << node.data;
    return os;
}
