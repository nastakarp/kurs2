//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "Status.h"
#include "../../Util.h"

// Определение конструктора
Status::Status(const char *playerStatus) {
    int len = length(playerStatus);
    status = new char[len + 1];
    copy(playerStatus, status, len);
}

// Определение деструктора
Status::~Status() {
    delete[] status; // Освобождение памяти, выделенной для статуса
}

std::ostream &operator<<(std::ostream &os, const Status &status) {
    os << status.status << " ";
    return os;
}


bool operator==(const Status &status1, const Status &status2) {
    return strcmp(status1.status, status2.status) == 0;
}