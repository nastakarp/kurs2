//
// Created by Анастасия on 01.05.2024.
//

#ifndef PROGA_KURS_PLAYER_H
#define PROGA_KURS_PLAYER_H

#include "Name.h"
#include "City.h"
#include "Position.h"
#include "Status.h"

struct Player{
    int id;
    Name name;
    City city;
    Position position;
    Status status;

    //TeamStatList;
};
#endif //PROGA_KURS_PLAYER_H
