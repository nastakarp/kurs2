//
// Created by Анастасия on 06.05.2024.
//

#include "Functional.h"
#include <iomanip>

//1 игроков, сгруппированные по позиции и возрастной категории
// Добавляем заголовочный файл для работы с файлами
void
printPlayersGroupedByPositionAndAgeCategory(PositionList *positionList, YearList *yearList, PlayerList *playerList) {
    std::ofstream outputFile("output1.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file";
        return;
    }

    auto positionNode = positionList->head;

    // Определим ширину каждого столбца
    int positionWidth = 15;
    int yearWidth = 8;
    int nameWidth = 25;

    // Заголовки таблицы
    outputFile << std::left << std::setw(positionWidth) << "Position" << std::setw(yearWidth) << "Year"
               << std::setw(nameWidth) << "Player"
               << std::endl;
    outputFile << std::setfill('-') << std::setw(positionWidth + yearWidth + nameWidth) << "" << std::setfill(' ')
               << std::endl;

    while (positionNode != nullptr) {
        auto yearNode = yearList->head;
        while (yearNode != nullptr) {
            bool flag = false;
            auto playerNode = playerList->head;
            while (playerNode != nullptr) {
                if ((extractYear(playerNode->data.name->dateOfBirth) == yearNode->data.value) &&
                    (*playerNode->data.position == positionNode->data)) {
                    // Выводим данные игрока в виде строки таблицы
                    outputFile << std::left << std::setw(positionWidth) << positionNode->data.position
                               << std::setw(yearWidth) << yearNode->data.value
                               << std::setw(nameWidth) << (playerNode->data.name->fullname) << std::endl;
                    flag = true;
                }
                playerNode = playerNode->next;
            }
            yearNode = yearNode->next;
        }

        positionNode = positionNode->next;
    }

    outputFile.close();
}

//2 список игроков и кандидатов, которые играли ранее в одних командах
/*void printFormerTeammates(PlayerList& playerList) {
    // Проходим по всем игрокам
    auto currentPlayerNode = playerList.head;
    while (currentPlayerNode != nullptr) {
        Player& currentPlayer = currentPlayerNode->data;
        std::cout << "Player: " << currentPlayer.name->fullname << std::endl;
        std::cout << "Former Teammates:" << std::endl;

        // Создаем список, чтобы избежать дубликатов
        std::set<Player*> formerTeammates;

        // Проходим по всем статистикам команд текущего игрока
        auto currentTeamStatNode = currentPlayer.statList.head;
        while (currentTeamStatNode != nullptr) {
            TeamStat& currentTeamStat = currentTeamStatNode->data;

            // Проходим по всем игрокам в текущей команде
            auto otherPlayerNode = playerList.head;
            while (otherPlayerNode != nullptr) {
                Player& otherPlayer = otherPlayerNode->data;

                // Проверяем, не является ли другой игрок текущим игроком
                if (&otherPlayer != &currentPlayer) {
                    // Проверяем, есть ли у другого игрока статистика в текущей команде и добавляем его в список
                    if (otherPlayer.statList.findById(currentTeamStat.id) != nullptr) {
                        formerTeammates.insert(&otherPlayer);
                    }
                }

                otherPlayerNode = otherPlayerNode->next;
            }

            currentTeamStatNode = currentTeamStatNode->next;
        }

        // Выводим всех бывших партнеров по команде
        for (auto teammate : formerTeammates) {
            std::cout << "- " << teammate->name->fullname << std::endl;
        }

        std::cout << std::endl;

        currentPlayerNode = currentPlayerNode->next;
    }
}*/


//3 учетные карточки на каждого игрока, упорядоченные (отдельно) по общему числу игр, голов и голевых передач за все команды,
void printPlayerCards(PlayerList *playerList) {
    std::ofstream outputFile("output3.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file";
        return;
    }

    // Определим ширину каждого столбца
    int nameWidth = 35;
    int size = 15;

    // Заголовки таблицы
    outputFile << std::left << std::setw(nameWidth) << "Player" << std::setw(size) << "Matches"
               << std::setw(size) << "Goals Scored" << std::setw(size) << "Goals Conceded"
               << std::setw(size) << "Assists" << std::endl;
    outputFile << std::setfill('-') << std::setw(nameWidth + 4 * size) << "" << std::setfill(' ') << std::endl;

    auto playerNode = playerList->head;
    while (playerNode != nullptr) {
        auto teamstatNode = playerNode->data.statList.head;
        int sum_playedMatches = 0;
        int sum_goalsScored = 0;
        int sum_goalsConceded = 0;
        int sum_assists = 0;
        while (teamstatNode != nullptr) {
            sum_playedMatches += teamstatNode->data.playedMatches;
            sum_goalsScored += teamstatNode->data.goalsScored;
            sum_goalsConceded += teamstatNode->data.goalsConceded;
            sum_assists += teamstatNode->data.assists;
            //остальные голы
            teamstatNode = teamstatNode->next;
        }
        outputFile << std::left << std::setw(nameWidth) << playerNode->data.name->fullname << std::setw(size)
                   << sum_playedMatches << std::setw(size) << sum_goalsScored << std::setw(size) << sum_goalsConceded
                   << std::setw(size) << sum_assists << std::endl;
        playerNode = playerNode->next;
    }

    outputFile << std::endl;
    outputFile.close();
}
/*
while (playerNode != nullptr){
 auto teamstatNode=playernode.teamstat.head
 пробегаем по игроку
    пробегаем по teamstat
        суммируем голы за каждую команду
 */

//4 учетные карточки на каждого игрока команды, упорядоченные (отдельно) по общему числу игр, голов и голевых передач за команду
//void printTeamPlayerCards(PlayerList& playerList, teamName)
