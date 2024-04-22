//
// Created by Анастасия on 20.04.2024.
//

#include "PositionNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
PositionNode::PositionNode(const Position value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
PositionNode::~PositionNode() {
    // Поскольку data - объект типа Player, его деструктор будет вызван автоматически при удалении NameNode
}

// Оператор сравнения равенства NameNode
bool operator==(const PositionNode &lhs, const PositionNode &rhs) {
    // Сравниваем данные игроков
    return rhs.data.position == lhs.data.position;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const PositionNode &node) {
    os << node.data.position;
    return os;
}
