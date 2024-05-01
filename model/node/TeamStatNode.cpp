//
// Created by Анастасия on 21.04.2024.
//
#include "TeamStatNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
TeamStatNode::TeamStatNode(const TeamStat value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
TeamStatNode::~TeamStatNode() {
}

// Оператор сравнения равенства NameNode
bool operator==(const TeamStatNode &lhs, const TeamStatNode &rhs) {
    // Сравниваем данные игроков
    return lhs.data.name == rhs.data.name;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const TeamStatNode &node) {
    os << node.data.name;
    return os;
}
