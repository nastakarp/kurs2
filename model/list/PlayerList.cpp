//
// Created by Анастасия on 01.05.2024.
//

#include "PlayerList.h"
#include "../node/PlayerNode.h"

PlayerList::PlayerList() : head(nullptr), tail(nullptr) {
}


// Деструктор для освобождения памяти
PlayerList::~PlayerList() {
    PlayerNode *current = head; // Указатель на текущий узел

    while (current != nullptr) {
        PlayerNode *next = current->next; // Сохраняем указатель на следующий узел
        delete current; // Освобождаем память для текущего узла
        current = next; // Переходим к следующему узлу
    }

    head = nullptr; // Устанавливаем указатель на начало списка в nullptr
    tail = nullptr; // Устанавливаем указатель на конец списка в nullptr
}
Player & PlayerList::appendNode(Player *value) {
    // Проверяем, существует ли уже такое значение в списке
    PlayerNode *current = head;
    while (current != nullptr) {
        if (current->data == value) {
            // Значение уже присутствует в списке, поэтому выходим из функции
            return *current->data;
        }
        current = current->next;
    }
    // Создаем новый узел с заданным значением
    auto *newNode = new PlayerNode(value);

    // Если список пуст, устанавливаем новый узел как начало и конец списка
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        // Добавляем новый узел в конец списка и обновляем указатель на хвост
        tail->next = newNode;
        tail = newNode;
    }
    return *newNode->data;
}


Player *PlayerList::findById(int playerId) const {
    auto currentNode = this->head;
    // Начинаем с головы списка
    while (currentNode != nullptr) {
        if (currentNode->data->idPlayer == playerId) {
            return currentNode->data; // Возвращаем указатель на игрока, если найден
        }
        currentNode = currentNode->next; // Переходим к следующему узлу
    }
    return nullptr; // Если игрок с указанным идентификатором не найден, возвращаем nullptr
}

// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const PlayerList &list) {
    PlayerNode *current = list.head;
    while (current != nullptr) {
        os << current->data << " -> ";
        current = current->next;
    }
    return os;
}
