//
// Created by Анастасия on 06.05.2024.
//

#ifndef PROGA_KURS_TEAMNAME_H
#define PROGA_KURS_TEAMNAME_H

struct TeamName {
    char *teamName; // Имя команды
    // Конструктор
    TeamName(const char *teamName);

    // Деструктор
    ~TeamName();

    // Перегрузка оператора вывода для вывода объекта в поток
    friend std::ostream &operator<<(std::ostream &os, const TeamName &teamName);

    // Перегрузка оператора сравнения для сравнения двух объектов TeamName
    friend bool operator==(const TeamName &teamName1, const TeamName &teamName2);
};

#endif //PROGA_KURS_TEAMNAME_H
