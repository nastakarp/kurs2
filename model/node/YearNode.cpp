//
// Created by Анастасия on 05.05.2024.
//

#include "YearNode.h"


// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
YearNode::YearNode(const Year value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
YearNode::~YearNode() {
    // Поскольку data - объект типа Year, его деструктор будет вызван автоматически при удалении YearNode
}

// Оператор сравнения равенства YearNode
bool operator==(const YearNode &lhs, const YearNode &rhs) {
    // Сравниваем данные годов
    return lhs.data == rhs.data;
}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const YearNode &node) {
    os << node.data;
    return os;
}
