//
// Created by Анастасия on 07.05.2024.
//

#include "Team.h"
#include <iostream>
#include "../../Util.h"


// Определение конструктора
Team::Team(const char *teamName) {
    int len = length(teamName);
    this->team = new char[len + 1];
    copy(teamName, this->team, len);
}

// Определение деструктора
Team::~Team() {
    delete[] team;
}
// Оператор вывода узла в поток
std::ostream &operator<<(std::ostream &os, const Team &team) {
    os << team.team << " ";
    return os;
}

bool operator==(const Team &team1, const Team &team2) {
    return strcmp(team1.team, team2.team) == 0;
}