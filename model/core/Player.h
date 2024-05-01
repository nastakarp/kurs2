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

struct Player{
    Player(int id, const Name &playerName, const City &playerCity, Position playerPosition, Status playerStatus,
           TeamStatList list);

    int idPlayer;
    Name name;
    City city;
    Position position;
    Status status;
};
#endif //PROGA_KURS_PLAYER_H
