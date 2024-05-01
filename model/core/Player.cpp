#include "Player.h"
#include "../list/TeamStatList.h"

//
// Created by Анастасия on 01.05.2024.
//
Player::Player(int id, const Name &playerName, const City &playerCity, Position playerPosition, Status playerStatus,
               TeamStatList list) :
        idPlayer(id),
        name(playerName),
        city(playerCity),
        position(playerPosition),
        status(playerStatus) {}