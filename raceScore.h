//
// Created by klonek on 22.05.19.
//

#ifndef PROJEKT_RACE_H
#include <stdio.h>
#include <stdlib.h>
#define PROJEKT_RACE_H
 struct RaceScore{
    char * raceName;
    char * date;
    char * time;
    int position;
    int differenceInPosition;
    struct RaceScore *next;
};

struct RaceScore *addScore(struct RaceScore *list,  char * raceName, char * date, char * time, int position, int differenceInPosition);
void deleteScores(struct RaceScore *list);
#endif //PROJEKT_RACE_H

