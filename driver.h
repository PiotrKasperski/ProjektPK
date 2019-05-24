//
// Created by klonek on 22.05.19.
//
#include "raceScore.h"
#include <string.h>

#ifndef PROJEKT_DRIVER_H
#define PROJEKT_DRIVER_H

typedef struct Driver {
    char *name;
    RaceScore *score;
    struct Driver *next;
} Driver;


Driver *addDriverScore(Driver *list, char *driverName, char *raceName, char *date, char *time, int position,
               int differenceInPosition);

Driver *saveResults(char *result, char *raceName, char *date, Driver *list);

void deleteDriverList(Driver *list);

void deleteLast(char *str, const char ch);

#endif //PROJEKT_DRIVER_H