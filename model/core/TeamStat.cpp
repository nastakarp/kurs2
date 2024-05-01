//
// Created by Анастасия on 17.04.2024.
//
#include <iostream>
#include "TeamStat.h"
#include "../../Util.h"

// Конструктор
TeamStat::TeamStat(const char *cmd, int playedMatches, int goalsScored, int goalsConceded, int assists) {
    int len = length(cmd);
    name = new char[len + 1];
    copy(cmd, name, len);
    this->playedMatches = playedMatches;
    this->goalsScored = goalsScored;
    this->goalsConceded = goalsConceded;
    this->assists = assists;
}

// Деструктор
TeamStat::~TeamStat() {
    delete[]name;

}

std::ostream &operator<<(std::ostream &os, const TeamStat &stat) {
    os << stat.name << " " << stat.playedMatches << " " << stat.goalsScored << " " << stat.goalsConceded << " "
       << stat.assists;
    return os;
}

bool operator==(const TeamStat &name1, const TeamStat &name2) {
    return strcmp(name1.name, name2.name) == 0;
}
