//
// Created by Анастасия on 22.04.2024.
//
#include "NameList.h"
#include "../node/NameNode.h"

NameList::NameList() : head(nullptr), tail(nullptr) {
}


// Деструктор для освобождения памяти
NameList::~NameList() {
    NameNode *current = head; // Указатель на текущий узел

    while (current != nullptr) {
        NameNode *next = current->next; // Сохраняем указатель на следующий узел
        delete current; // Освобождаем память для текущего узла
        current = next; // Переходим к следующему узлу
    }

    head = nullptr; // Устанавливаем указатель на начало списка в nullptr
    tail = nullptr; // Устанавливаем указатель на конец списка в nullptr
}

// Добавление узла в конец списка
Name& NameList::appendNode(const Name& value) {
    // Проверяем, существует ли уже такое значение в списке
    NameNode *current = head;
    while (current != nullptr) {
        if (current->data == value) {
            // Значение уже присутствует в списке, поэтому возвращаем ссылку на data
            return current->data;
        }
        current = current->next;
    }

    // Создаем новый узел с заданным значением
    auto *newNode = new NameNode(value);

    // Если список пуст, устанавливаем новый узел как начало и конец списка
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Добавляем новый узел в конец списка и обновляем указатель на хвост
        tail->next = newNode;
        tail = newNode;
    }

    // Возвращаем ссылку на data нового узла
    return newNode->data;
}



// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const NameList &list) {
    NameNode *current = list.head;
    while (current != nullptr) {
        os << current->data << " -> ";
        current = current->next;
    }
    os << "NULL";
    return os;
}

