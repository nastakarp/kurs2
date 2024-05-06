//
// Created by Анастасия on 07.05.2024.
//

#include "TeamList.h"

TeamList::TeamList() : head(nullptr), tail(nullptr) {
}


// Деструктор для освобождения памяти
TeamList::~TeamList() {
    TeamNode *current = head; // Указатель на текущий узел

    while (current != nullptr) {
        TeamNode *next = current->next; // Сохраняем указатель на следующий узел
        delete current; // Освобождаем память для текущего узла
        current = next; // Переходим к следующему узлу
    }

    head = nullptr; // Устанавливаем указатель на начало списка в nullptr
    tail = nullptr; // Устанавливаем указатель на конец списка в nullptr
}
// Добавление узла в конец списка
TeamNode * TeamList::appendNode(Team* value) {

    // Проверяем, существует ли уже такое значение в списке
    TeamNode *current = head;
    while (current != nullptr) {
        if (*(current->data) == *value) {
            // Значение уже присутствует в списке, поэтому возвращаем указатель на текущий узел
            return current;
        }
        current = current->next;
    }

    // Создаем новый узел с заданными данными
    auto *newNode = new TeamNode(value);

    // Если список пуст, устанавливаем новый узел как начало и конец списка
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Добавляем новый узел в конец списка и обновляем указатель на хвост
        tail->next = newNode;
        tail = newNode;
    }

    // Возвращаем указатель на только что добавленный узел
    return newNode;
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const TeamList &list) {
    TeamNode *current = list.head;
    while (current != nullptr) {
        os << current->data << " -> ";
        current = current->next;
    }
    os << "NULL";
    return os;
}

