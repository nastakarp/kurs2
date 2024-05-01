#include <iostream>
#include <fstream>

#include "model/core/Name.h"
#include "model/core/City.h"
#include "model/core/Position.h"
#include "model/core/Status.h"
#include "model/core/TeamStat.h"
#include "model/core/Player.h"

#include "model/list/NameList.h"
#include "model/list/CityList.h"
#include "model/list/PositionList.h"
#include "model/list/StatusList.h"
#include "model/list/TeamStatList.h"
#include "model/list/PlayerList.h"

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
    PlayerList playerList;

    while (!input.eof()) {
        int id = charToInt(readUntilComma(input));

        char *fullname = readUntilComma(input);
        char *dob = readUntilComma(input);
        //std::cout<<fullname<<" " <<dob<<std::endl;
        Name name(fullname, dob);
        nameList.appendNode(name);

        City city(readUntilComma(input));
        cityList.appendNode(city);

        Position position(readUntilComma(input));
        positionList.appendNode(position);

        Status status(readUntilComma(input));
        statusList.appendNode(status);

        Player player(id, name, city, position, status, TeamStatList() );
    }


    ifstream team("team.txt", std::ios::in);
    if (!team.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    while (!team.eof()){
        int playerId;
        char* teamname =readUntilComma(team);
        int a = charToInt(readUntilComma(team));
        //TeamName teamName(teamname,a,b,c,d);
        //Player player = playerList.findById(playerId);
        //player.teamNameList.appendNode(timeName)
    }
    /*
    std::cout << nameList.head->data << std::endl;
    std::cout << cityList.head->data << std::endl;
    std::cout << positionList.head->data << std::endl;
    std::cout << statusList.head->data << std::endl;*/

    input.close();

    return 0;
}



