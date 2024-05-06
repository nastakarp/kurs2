//
// Created by Анастасия on 17.04.2024.
//
#include <iostream>
#include "TeamStat.h"
#include "../../Util.h"

// Конструктор для инициализации данных командной статистики
TeamStat::TeamStat(Team *teamPtr, int playedMatches, int goalsScored, int goalsConceded, int assists) :
        team(teamPtr),
        playedMatches(playedMatches),
        goalsScored(goalsScored),
        goalsConceded(goalsConceded),
        assists(assists) {}

// Деструктор для освобождения ресурсов
TeamStat::~TeamStat() {
    // Ничего не нужно удалять, так как team - это просто указатель на объект команды, который должен быть удален отдельно
}

std::ostream &operator<<(std::ostream &os, const TeamStat &name) {
    os << *name.team << " "<<name.playedMatches;
    return os;
}

bool operator==(const TeamStat &name1, const TeamStat &name2) {
    return name1.team == name2.team;
}