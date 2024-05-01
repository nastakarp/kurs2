//
// Created by Анастасия on 01.05.2024.
//

#ifndef PROGA_KURS_PLAYER_H
#define PROGA_KURS_PLAYER_H

#include "Name.h"
#include "City.h"
#include "Position.h"
#include "Status.h"
#include "../list/TeamStatList.h"

struct Player {

    Player(int id, Name *playerName, City *playerCity, Position *playerPosition, Status *playerStatus);

    int idPlayer;
    Name *name;
    City *city;
    Position *position;
    Status *status;
    TeamStatList statList;

    ~Player();

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    friend bool operator==(const Player &lhs, const Player &rhs);

};

#endif //PROGA_KURS_PLAYER_H

