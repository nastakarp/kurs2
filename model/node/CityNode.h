//
// Created by Анастасия on 20.04.2024.
//

#ifndef PROGA_KURS_CITYNODE_H
#define PROGA_KURS_CITYNODE_H

#include <iostream>
#include "../core/City.h" // Подключаем заголовочный файл для структуры Team, если необходимо

struct CityNode {
    City *data; // Данные узла
    CityNode *next; // Указатель на следующий узел
    // Конструктор для инициализации узла с заданным значением и указателем на следующий узел
    CityNode(City* value);

    // Деструктор для освобождения ресурсов
    ~CityNode();

    // Оператор сравнения равенства NameNode
    friend bool operator==(const CityNode &lhs, const CityNode &rhs);

    // Вывод узла в поток
    friend std::ostream &operator<<(std::ostream &os, const CityNode &node);


};


#endif //PROGA_KURS_CITYNODE_H
