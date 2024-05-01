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
    ifstream player_input("player.txt", std::ios::in);
    if (!player_input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;

    }

    NameList nameList;
    CityList cityList;
    PositionList positionList;
    StatusList statusList;
    PlayerList playerList;


    while (!player_input.eof()) {
        int id = charToInt(readUntilComma(player_input));

        char *fullname = readUntilComma(player_input);
        char *dob = readUntilComma(player_input);
        //std::cout<<fullname<<" " <<dob<<std::endl;
        Name name(fullname, dob);
        Name &currentname = nameList.appendNode(name);

        City city(readUntilComma(player_input));
        City &currentcity = cityList.appendNode(city);

        Position position(readUntilComma(player_input));
        Position &positioncurrent = positionList.appendNode(position);

        Status status(readUntilComma(player_input));
        Status &statuscurrent = statusList.appendNode(status);

        Player player(id, &currentname, &currentcity, &positioncurrent, &statuscurrent);
        std::cout<<player<<std::endl;
    }


    ifstream team_input("team.txt", std::ios::in);
    if (!team_input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    TeamStatList teamStatList;
    while (!team_input.eof()) {
        int playerId = charToInt(readUntilComma(team_input));
        char *teamname = readUntilComma(team_input);
        int playedMatches = charToInt(readUntilComma(team_input));      // Сыгранные матчи
        int goalsScored = charToInt(readUntilComma(team_input));        // Забитые голы
        int goalsConceded = charToInt(readUntilComma(team_input));      // Пропущенные голы
        int assists = charToInt(readUntilComma(team_input));            // Голевые передачи
        TeamStat teamStat(teamname, playedMatches, goalsScored, goalsConceded, assists);
        teamStatList.appendNode(teamStat);
        //std::cout << playerId << " " << teamStat << std::endl;
        //Player player = playerList.findById(playerId);
        //player.teamStatList.appendNode(timeStat);
    }

    /*
    std::cout << nameList.head->data << std::endl;
    std::cout << cityList.head->data << std::endl;
    std::cout << positionList.head->data << std::endl;
    std::cout << statusList.head->data << std::endl;*/

    player_input.close();
    team_input.close();
    return 0;
}



