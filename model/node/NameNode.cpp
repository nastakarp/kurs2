#include "NameNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
NameNode::NameNode(Name* value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
NameNode::~NameNode() {
    // Поскольку data - объект типа Name, его деструктор будет вызван автоматически при удалении NameNode
}

// Оператор сравнения равенства NameNode
bool operator==(const NameNode &lhs, const NameNode &rhs) {
    // Сравниваем данные имен
    return lhs.data == rhs.data;

}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const NameNode &node) {
    os << node.data;
    return os;
}
/*
#include "NameNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
NameNode::NameNode(Name* value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
NameNode::~NameNode() {
    // Поскольку data - объект типа Name, его деструктор будет вызван автоматически при удалении NameNode
}

bool operator==(const NameNode &lhs, const NameNode &rhs) {
    // Сравниваем данные имен
    return lhs.data == rhs.data;
}*/
