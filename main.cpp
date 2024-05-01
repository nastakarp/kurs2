#include <iostream>
#include <fstream>

#include "model/core/Name.h"
#include "model/core/City.h"
#include "model/core/Position.h"
#include "model/core/Status.h"
#include "model/core/TeamName.h"

#include "model/list/NameList.h"
#include "model/list/CityList.h"
#include "model/list/PositionList.h"
#include "model/list/StatusList.h"
#include "model/list/TeamNameList.h"


int main() {
    setlocale(LC_ALL, "Russian");
    ifstream input("player.txt", std::ios::in);
    if (!input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    NameList nameList;
    CityList cityList;
    PositionList positionList;
    StatusList statusList;
    TeamNameList teamNameList;

    while (!input.eof()) {
        int id = charToInt(readUntilComma(input));
        Name name(readUntilComma(input), readUntilComma(input));
        nameList.appendNode(name);

        City city(readUntilComma(input));
        cityList.appendNode(city);

        Position position(readUntilComma(input));
        positionList.appendNode(position);

        Status status(readUntilComma(input));
        statusList.appendNode(status);
    }

    std::cout << nameList.head->data;
    std::cout << cityList.head->data;
    std::cout << positionList.head->data;
    std::cout << statusList.head->data;


    input.close();

    return 0;
}



