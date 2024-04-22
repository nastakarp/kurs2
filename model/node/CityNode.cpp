//
// Created by Анастасия on 20.04.2024.
//
#include "CityNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
CityNode::CityNode(const City value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
CityNode::~CityNode() {
    // Поскольку data - объект типа Player, его деструктор будет вызван автоматически при удалении NameNode
}

// Оператор сравнения равенства NameNode
bool operator==(const CityNode &lhs, const CityNode &rhs) {
    // Сравниваем данные игроков
    return lhs.data.city == rhs.data.city;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const CityNode &node) {
    os <<node.data.city;
    return os;
}
