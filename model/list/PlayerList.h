//
// Created by Анастасия on 01.05.2024.
//

#ifndef PROGA_KURS_PLAYERLIST_H
#define PROGA_KURS_PLAYERLIST_H

#include <iostream>
#include "../node/PlayerNode.h"

struct PlayerList {
    PlayerNode *head; // Указатель на начало списка
    PlayerNode *tail; // Указатель на конец списка

    // Конструктор по умолчанию
    PlayerList();

    // Деструктор для освобождения памяти
    ~PlayerList();

    // Добавление узла в конец списка
    //void appendNode(const Player value);

    // Функция для поиска игрока по идентификатору в списке игроков
    //Player *findById(const PlayerList &playerList, int playerId);

    // Оператор вывода узла в поток
    //friend std::ostream &operator<<(std::ostream &os, const PlayerList &list);
};

#endif //PROGA_KURS_PLAYERLIST_H
