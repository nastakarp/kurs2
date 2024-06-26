//
// Created by Анастасия on 01.05.2024.
//

#include "PlayerNode.h"


// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
PlayerNode::PlayerNode(Player *value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
PlayerNode::~PlayerNode() {
}

// Оператор сравнения равенства NameNode
bool operator==(const PlayerNode &lhs, const PlayerNode &rhs) {
    // Сравниваем данные игроков
    return rhs.data->idPlayer == lhs.data->idPlayer;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const PlayerNode &node) {
    os << node.data;
    return os;
}
