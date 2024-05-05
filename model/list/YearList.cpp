//
// Created by Анастасия on 05.05.2024.
//

#include "YearList.h"


YearList::YearList() : head(nullptr), tail(nullptr) {}

YearList::~YearList() {
    YearNode *current = head;

    while (current != nullptr) {
        YearNode *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
}
Year& YearList::appendNode(const int yearValue) {
    // Проверяем, существует ли уже такое значение в списке
    YearNode *current = head;
    while (current != nullptr) {
        if (current->data.value == yearValue) {
            return current->data; // Если значение уже есть в списке, возвращаем его
        }
        current = current->next;
    }

    // Создаем объект Year и добавляем его в отсортированном порядке
    YearNode *newNode = new YearNode(Year(yearValue));

    // Если список пуст или новый узел должен быть первым
    if (head == nullptr || head->data.value > yearValue) {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        return newNode->data;
    }

    // Ищем место для вставки нового узла
    current = head;
    while (current->next != nullptr && current->next->data.value < yearValue) {
        current = current->next;
    }

    // Вставляем новый узел между текущим и следующим узлом
    newNode->next = current->next;
    current->next = newNode;

    // Если вставлен в конец списка, обновляем указатель на хвост
    if (newNode->next == nullptr) {
        tail = newNode;
    }

    return newNode->data;
}


std::ostream &operator<<(std::ostream &os, const YearList &list) {
    YearNode *current = list.head;
    while (current != nullptr) {
        os << current->data << " -> ";
        current = current->next;
    }
    os << "NULL";
    return os;
}
