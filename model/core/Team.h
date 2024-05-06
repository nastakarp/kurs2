//
// Created by Анастасия on 07.05.2024.
//

#ifndef PROGA_KURS_TEAM_H
#define PROGA_KURS_TEAM_H
#include <iostream>

struct Team {
    char *team;

    // Конструктор
    explicit Team(const char *teamName);

    // Деструктор
    ~Team();

    friend std::ostream &operator<<(std::ostream &os, const Team &team);

    friend bool operator==(const Team &team1, const Team &team2);
};
#endif //PROGA_KURS_TEAM_H
