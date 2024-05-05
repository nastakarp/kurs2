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
//1 игроков, сгруппированные по позиции и возрастной категории
// Добавляем заголовочный файл для работы с файлами

#include <iomanip> // Добавляем заголовочный файл для манипуляторов вывода

void printPlayersGroupedByPositionAndAgeCategory(PositionList *positionList, YearList *yearList, PlayerList *playerList) {
    ofstream outputFile("output1.txt");
    if (!outputFile.is_open()) {
        cerr << "Unable to open output file";
        return;
    }

    auto positionNode = positionList->head;
    while (positionNode != nullptr) {
        outputFile << setw(10) << positionNode->data.position << '\n'; // Выравниваем по символам
        auto yearNode = yearList->head;
        while (yearNode != nullptr) {
            bool flag = false;
            auto playerNode = playerList->head;
            while (playerNode != nullptr) {

                if ((extractYear(playerNode->data.name->dateOfBirth) == yearNode->data.value) &&
                    (*playerNode->data.position == positionNode->data)) {
                    if (!flag) outputFile << setw(5) << yearNode->data.value ; // Выравниваем по символам
                    flag = true;
                    outputFile << setw(40) << (playerNode->data.name->fullname) ; // Выравниваем по символам
                }
                playerNode = playerNode->next;
            }
            if (flag) outputFile << endl;
            yearNode = yearNode->next;
        }

        outputFile << endl;
        positionNode = positionNode->next;
    }

    outputFile.close();
}


//2 список игроков и кандидатов, которые играли ранее в одних командах


//3 учетные карточки на каждого игрока, упорядоченные (отдельно) по общему числу игр, голов и голевых передач за все команды,
void kart(PlayerList *playerList) {
    auto playerNode = playerList->head;
    while (playerNode != nullptr) {
        auto teamstatNode = playerNode->data.statList.head;
        int sumplayedMatches = 0;
        while (teamstatNode != nullptr) {
            sumplayedMatches += teamstatNode->data.playedMatches;
            //остальные голы
            teamstatNode = teamstatNode->next;
        }
        cout << playerNode->data.name->fullname << '\t';
        cout << sumplayedMatches << '\t';
        playerNode = playerNode->next;
        cout << endl;
    }
    cout << endl;
}
/*
while (playerNode != nullptr){
 auto teamstatNode=playernode.teamstat.head
 пробегаем по игроку
    пробегаем по teamstat
        суммируем голы за каждую команду
 */
//4 учетные карточки на каждого игрока команды, упорядоченные (отдельно) по общему числу игр, голов и голевых передач за команду

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

        char *fullname = readUntilComma(player_input);
        char *dob = readUntilComma(player_input);

        Name name(fullname, dob);
        Name &currentname = nameList.appendNode(name);

        Year year(extractYear(dob));
        Year currentyear = yearList.appendNode(year.value);

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
    //std::cout  << yearList << std::endl;
    ifstream team_input("team.txt", std::ios::in);
    if (!team_input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
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

    printPlayersGroupedByPositionAndAgeCategory(&positionList, &yearList, &playerList);
    kart(&playerList);
    return 0;
}



