//
// Created by Анастасия on 21.04.2024.
//
#include "TeamNameNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
TeamNameNode::TeamNameNode(const TeamName value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
TeamNameNode::~TeamNameNode() {
}

// Оператор сравнения равенства NameNode
bool operator==(const TeamNameNode &lhs, const TeamNameNode &rhs) {
    // Сравниваем данные игроков
    return lhs.data.name == rhs.data.name;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const TeamNameNode &node) {
    os <<node.data.name;
    return os;
}
