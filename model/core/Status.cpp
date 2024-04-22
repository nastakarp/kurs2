//
// Created by Анастасия on 18.04.2024.
//
#include <iostream>
#include "Status.h"
#include "../../Util.h"
// Определение конструктора
Status::Status(const char* playerStatus) {
    int len = length(playerStatus);
    status = new char[len + 1];
    copy(playerStatus, status, len);
}

// Определение деструктора
Status::~Status() {
    delete[] status; // Освобождение памяти, выделенной для статуса
}


