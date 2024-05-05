//
// Created by Анастасия on 06.05.2024.
//

#ifndef PROGA_KURS_FUNCTIONAL_H
#define PROGA_KURS_FUNCTIONAL_H

#include <iomanip>
#include "model/list/PositionList.h"
#include "model/list/YearList.h"
#include "model/list/PlayerList.h"

void
printPlayersGroupedByPositionAndAgeCategory(PositionList *positionList, YearList *yearList, PlayerList *playerList);

void printPlayerCards(PlayerList *playerList);

#endif //PROGA_KURS_FUNCTIONAL_H
