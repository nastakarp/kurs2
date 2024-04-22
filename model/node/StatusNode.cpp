//
// Created by Анастасия on 21.04.2024.
//

#include "StatusNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
StatusNode::StatusNode(const Status value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
StatusNode::~StatusNode() {}

// Оператор сравнения равенства NameNode
bool operator==(const StatusNode &lhs, const StatusNode &rhs) {
    // Сравниваем данные игроков
    return lhs.data.status == rhs.data.status;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const StatusNode &node) {
    os <<node.data.status;
    return os;
}
