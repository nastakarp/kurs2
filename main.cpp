#include <iostream>
#include "model/core/Name.h"
#include "model/core/City.h"
#include "model/core/Position.h"
#include "model/core/Status.h"
#include "model/core/TeamName.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание экземпляра структуры Player с использованием конструктора
    Name person("Karpenko", "Anastasia ", "Yuryevna", "2005-09-20");

    // Вывод на экран
    std::cout << "surname: " << person.lastName << std::endl;
    std::cout << "name: " << person.firstName << std::endl;
    std::cout << "patronymic: " << person.patronymic << std::endl;
    std::cout << "dateOfBirth: " << person.dateOfBirth << std::endl;

    int yearOfBirth = extractYear(person.dateOfBirth);
    std::cout << "Year of Birth: " << yearOfBirth << std::endl;
    // Создание экземпляра структуры City с использованием конструктора
    City city("Saratov");

    // Вывод на экран
    std::cout << "city: " << city.city << std::endl;

    // Создание экземпляров структуры Player с использованием конструктора
    Position player("Torwart");

    // Вывод на экран позиций игроков
    std::cout << "position: " << player.position << std::endl;

    // Создание экземпляров структуры PlayerStatus с использованием конструктора
    Status status("candidate");

    // Вывод на экран статусов игроков
    std::cout << "status: " << status.status << std::endl;

    // Создание экземпляра структуры Command с использованием конструктора
    TeamName cmd("FK Saratov");

    // Вывод на экран
    std::cout << "team: " << cmd.name << std::endl;

    return 0;
}



