//
// Created by Анастасия on 17.04.2024.
//
#include <iostream>
#include "TeamName.h"
#include "../../Util.h"

// Конструктор
TeamName::TeamName(const char *cmd) {
    int len = length(cmd);
    name = new char[len + 1];
    copy(cmd, name, len);
}

// Деструктор
TeamName::~TeamName() {
    delete[]name;
}

std::ostream &operator<<(std::ostream &os, const TeamName &name) {
    os << name.name << " ";
    return os;
}
bool operator==(const TeamName &name1, const TeamName &name2) {
    return strcmp(name1.name, name2.name) == 0;
}
