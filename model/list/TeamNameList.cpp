//
// Created by Анастасия on 23.04.2024.
//

#include "TeamNameList.h"
#include "../node/TeamNameNode.h"

TeamNameList::TeamNameList() : head(nullptr), tail(nullptr) {
}


// Деструктор для освобождения памяти
TeamNameList::~TeamNameList() {
    TeamNameNode *current = head; // Указатель на текущий узел

    while (current != nullptr) {
        TeamNameNode *next = current->next; // Сохраняем указатель на следующий узел
        delete current; // Освобождаем память для текущего узла
        current = next; // Переходим к следующему узлу
    }

    head = nullptr; // Устанавливаем указатель на начало списка в nullptr
    tail = nullptr; // Устанавливаем указатель на конец списка в nullptr
}

// Добавление узла в конец списка
void TeamNameList::appendNode(const TeamName value) {
    // Создаем новый узел с заданным значением
    auto *newNode = new TeamNameNode(value);

    // Если список пуст, устанавливаем новый узел как начало и конец списка
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Добавляем новый узел в конец списка и обновляем указатель на хвост
        tail->next = newNode;
        tail = newNode;
    }
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const TeamNameList &list) {
    TeamNameNode *current = list.head;
    while (current != nullptr) {
        os << current->data << " -> ";
        current = current->next;
    }
    os << "NULL";
    return os;
}

