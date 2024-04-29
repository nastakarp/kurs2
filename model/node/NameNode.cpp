#include "NameNode.h"

// Конструктор для инициализации узла с заданным значением и указателем на следующий узел
NameNode::NameNode(const Name value) : data(value), next(nullptr) {}

// Деструктор для освобождения ресурсов
NameNode::~NameNode() {
    // Поскольку data - объект типа Name, его деструктор будет вызван автоматически при удалении NameNode
}

// Оператор сравнения равенства NameNode
bool operator==(const NameNode &lhs, const NameNode &rhs) {
    // Сравниваем данные имен
    return lhs.data.lastName == rhs.data.lastName &&
           lhs.data.firstName == rhs.data.firstName &&
           lhs.data.patronymic == rhs.data.patronymic;

}

// Вывод узла в поток
std::ostream &operator<<(std::ostream &os, const NameNode &node) {
    os << node.data.lastName << " " << node.data.firstName << " " << node.data.patronymic;
    return os;
}
