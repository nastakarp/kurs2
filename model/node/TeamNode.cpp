//
// Created by Анастасия on 07.05.2024.
//

#include "TeamNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
TeamNode::TeamNode(Team* value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
TeamNode::~TeamNode() = default;

// Оператор сравнения равенства NameNode
bool operator==(const TeamNode &lhs, const TeamNode &rhs) {
    // Сравниваем данные игроков
    return lhs.data == rhs.data;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const TeamNode &node) {
    os << node.data;
    return os;
}