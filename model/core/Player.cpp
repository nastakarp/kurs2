#include "Player.h"

Player::Player(int id, Name* playerName, City* playerCity, Position* playerPosition, Status* playerStatus)
        : idPlayer(id), name(playerName), city(playerCity), position(playerPosition), status(playerStatus) {}

Player::~Player() = default;

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << player.idPlayer << " ";
    os << *(player.name) << " ";
    os << *(player.city) << " ";
    os << *(player.position) << " ";
    os << *(player.status) << " ";
    //os << player.statList;
    return os;
}

bool operator==(const Player &lhs, const Player &rhs) {
    // Сравниваем все поля структуры Player
    return lhs.idPlayer == rhs.idPlayer;
}
