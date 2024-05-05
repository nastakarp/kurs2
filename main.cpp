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

#include "Functional.h"

void readPlayerData(const char *filename, NameList &nameList, CityList &cityList, PositionList &positionList,
                    StatusList &statusList, PlayerList &playerList, YearList &yearList) {
    std::ifstream player_input(filename, std::ios::in);
    if (!player_input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    while (!player_input.eof()) {
        int id = charToInt(readUntilComma(player_input));

        char *fullname = readUntilComma(player_input);
        char *dob = readUntilComma(player_input);

        Name name(fullname, dob);
        Name &currentname = nameList.appendNode(name);

        Year year(extractYear(dob));
        Year &currentyear = yearList.appendNode(year.value);

        City city(readUntilComma(player_input));
        City &currentcity = cityList.appendNode(city);

        Position position(readUntilComma(player_input));
        Position &positioncurrent = positionList.appendNode(position);

        Status status(readUntilComma(player_input));
        Status &statuscurrent = statusList.appendNode(status);

        Player player(id, &currentname, &currentcity, &positioncurrent, &statuscurrent);

        playerList.appendNode(player);
    }
    player_input.close();
}

void readTeamData(const std::string &filename, PlayerList &playerList) {
    std::ifstream team_input(filename);
    if (!team_input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    while (!team_input.eof()) {
        int playerId = charToInt(readUntilComma(team_input));
        char *teamname = readUntilComma(team_input);
        int playedMatches = charToInt(readUntilComma(team_input));      // Сыгранные матчи
        int goalsScored = charToInt(readUntilComma(team_input));        // Забитые голы
        int goalsConceded = charToInt(readUntilComma(team_input));      // Пропущенные голы
        int assists = charToInt(readUntilComma(team_input));            // Голевые передачи
        TeamStat teamStat(teamname, playedMatches, goalsScored, goalsConceded, assists);
        Player *player = playerList.findById(playerId);
        if (player != nullptr) {
            player->statList.appendNode(teamStat);
        }
    }

    team_input.close();
}

int main() {
    NameList nameList;
    CityList cityList;
    PositionList positionList;
    StatusList statusList;
    PlayerList playerList;
    YearList yearList;

    // Чтение данных о игроках
    readPlayerData("player.txt", nameList, cityList, positionList, statusList, playerList, yearList);

    // Чтение данных о командах
    readTeamData("team.txt", playerList);

    int choice;
    bool exitMenu = false;

    while (!exitMenu) {
        // Выводим меню
        std::cout << "Select a function:" << std::endl;
        std::cout << "1. list of players grouped by position and age category" << std::endl;
        std::cout << "2. list of players and candidates who have previously played in the same teams" << std::endl;
        std::cout
                << "3. scorecards for each player, ordered (separately) by the total number of games, goals and assists for all teams"
                << std::endl;
        std::cout
                << "4. registration cards for each player of the team, ordered (separately) by the total number of games, goals and assists for the team"
                << std::endl;
        std::cout << "5. exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        // Обрабатываем выбор пользователя
        switch (choice) {
            case 1:
                printPlayersGroupedByPositionAndAgeCategory(&positionList, &yearList, &playerList);
                break;
            case 2:
                std::cout << "2 in working" << std::endl;
                break;
            case 3:
                printPlayerCards(&playerList);
                break;
            case 4:
                std::cout << "4 in working" << std::endl;
                break;
            case 5:
                exitMenu = true;
                break;
            default:
                std::cout << "Wrong choice. Try again" << std::endl;
                break;
        }
    }

    return 0;
}



