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
#include "model/list/PlayerList.h"
#include "model/list/YearList.h"

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
    YearList yearList;

    while (!player_input.eof()) {
        int id = charToInt(readUntilComma(player_input));
        //std::cout<<id<<std::endl;
        char *fullname = readUntilComma(player_input);
        char *dob = readUntilComma(player_input);
        //std::cout<<fullname<<" " <<dob<<std::endl;

        Name name(fullname, dob);
        auto namePtr = nameList.appendNode(&name); // Вызываем метод и получаем указатель на добавленный узел
        //std::cout<<*namePtr->data<<std::endl;

        //Year year(extractYear(dob));
        yearList.appendNode(extractYear(dob)) ;

        City city(readUntilComma(player_input));
        auto cityPtr=cityList.appendNode(&city);
        //std::cout<<*cityPtr->data <<std::endl;

        Position position(readUntilComma(player_input));
        auto positionPtr=positionList.appendNode(&position);
        //std::cout<<*positionPtr->data<<std::endl;

        Status status(readUntilComma(player_input));
        auto statusPtr=statusList.appendNode(&status);
        //std::cout<<*statusPtr->data<<std::endl;

        Player player = Player(
                id,
                namePtr->data,
                cityPtr->data,
                positionPtr->data,
                statusPtr->data
        );
        playerList.appendNode(player);
    }
    //cout<<playerList;
    //cout<<yearList;
    auto currentNode = playerList.head;
    // Начинаем с головы списка
    while (currentNode != nullptr) {
        cout<<currentNode->data<<endl;
        currentNode = currentNode->next; // Переходим к следующему узлу
    }

    ifstream team_input("team.txt", std::ios::in);
    if (!team_input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    while (!team_input.eof()) {
        int playerId = charToInt(readUntilComma(team_input));
        char *teamname = readUntilComma(team_input);
        Team team(teamname);
        //std::cout<<team<<std::endl;
        int playedMatches = charToInt(readUntilComma(team_input));      // Сыгранные матчи
        int goalsScored = charToInt(readUntilComma(team_input));        // Забитые голы
        int goalsConceded = charToInt(readUntilComma(team_input));      // Пропущенные голы
        int assists = charToInt(readUntilComma(team_input));            // Голевые передачи
        TeamStat teamStat(&team, playedMatches, goalsScored, goalsConceded, assists);
        //cout<<teamStat<<endl;
        Player *player = playerList.findById(playerId);
        if (player != nullptr) {
            player->statList.appendNode(teamStat);
        }
        //cout<<*player<<endl;
    }

    player_input.close();
    team_input.close();

    return 0;
}