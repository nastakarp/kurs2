//
// Created by Анастасия on 21.04.2024.
//

#ifndef PROGA_KURS_TEAMSTAT_H
#define PROGA_KURS_TEAMSTAT_H

#include "../../Util.h" // Включаем заголовочный файл с определениями функций length(), copy() и cleanup()
#include <iostream> // Для использования объекта потока std::cout

struct TeamStat {

    char *name;
    int playedMatches = 0;      // Сыгранные матчи
    int goalsScored = 0;        // Забитые голы
    int goalsConceded = 0;      // Пропущенные голы
    int assists = 0;            // Голевые передачи
    // Конструктор
    TeamStat(const char *cmd, int playedMatches, int goalsScored, int goalsConceded, int assists);

    // Деструктор
    ~TeamStat();

    friend std::ostream &operator<<(std::ostream &os, const TeamStat &name);

    friend bool operator==(const TeamStat &name1, const TeamStat &name2);
};


#endif //PROGA_KURS_TEAMSTAT_H
