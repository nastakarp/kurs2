//
// Created by Анастасия on 21.04.2024.
//

#ifndef PROGA_KURS_STATUS_H
#define PROGA_KURS_STATUS_H

struct Status {
    char *status;

    // Конструктор
    Status(const char *playerStatus);

    // Деструктор
    ~Status();

    friend std::ostream &operator<<(std::ostream &os, const Status &status);

    friend bool operator==(const Status &status1, const Status &status2);
};

#endif //PROGA_KURS_STATUS_H
