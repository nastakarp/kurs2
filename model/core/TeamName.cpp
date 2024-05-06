//
// Created by Анастасия on 06.05.2024.
//
#include <iostream>
#include "../../Util.h"
#include "TeamName.h"

TeamName::TeamName(const char* teamName) {
    int len = length(teamName);
    teamName = new char[len + 1];
    copy(teamName, this->teamName, len);
}

// Деструктор
TeamName::~TeamName() {
    delete[] teamName;
}

// Перегрузка оператора вывода для вывода объекта в поток
std::ostream& operator<<(std::ostream& os, const TeamName& teamName) {
    os << teamName.teamName << " ";
    return os;
}

// Перегрузка оператора сравнения для сравнения двух объектов TeamName
bool operator==(const TeamName& teamName1, const TeamName& teamName2) {
    return strcmp(teamName1.teamName, teamName2.teamName) == 0;
}
