//
// Created by klonek on 22.05.19.
//
#include "raceScore.h"
#include <string.h>

struct Driver {
    char *name;
    struct RaceScore *score;
    struct Driver *next;
};


struct Driver *getDriver(struct Driver *list, char *driverName);

struct Driver *addDriver(struct Driver *list, char *driverName);

struct Driver *
addDriverScore(struct Driver *list, char *driverName, char *raceName, char *date, char *time, int position,
               int differenceInPosition);

void deleteDriverList(struct Driver *list);