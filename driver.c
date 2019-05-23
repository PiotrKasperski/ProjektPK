//
// Created by klonek on 22.05.19.
//

#include "driver.h"

struct Driver *getDriver(struct Driver *list, char *driverName) {
    struct Driver *tmp = (struct Driver *) malloc(sizeof(struct Driver));
    if (list != NULL) {
        if (strcmp(list->name, driverName) == 0) return list;
        while (list->next != NULL) {
            if (strcmp(list->next->name, driverName) == 0) return list->next;
            list = list->next;

        }

        list->next = (struct Driver *) malloc(sizeof(struct Driver));
        list->next->next = NULL;
        list->next->name = driverName;
        list->next->score = NULL;
        return list->next;
    } else {
        tmp->name = driverName;
        tmp->score = NULL;
        tmp->next = NULL;
        return tmp;
    }
}

struct Driver *addDriver(struct Driver *list, char *driverName) {
    struct Driver *tmp = (struct Driver *) malloc(sizeof(struct Driver));
    if (list != NULL) {
        tmp = list;
        if (strcmp(list->name, driverName) == 0) return tmp;
        while (list->next != NULL) {
            if (strcmp(list->name, driverName) == 0) return tmp;
            list = list->next;

        }

        list->next = (struct Driver *) malloc(sizeof(struct Driver));
        list->next->next = NULL;
        list->next->name = driverName;
        list->next->score = NULL;
    } else {
        tmp->name = driverName;
        tmp->score = NULL;
        tmp->next = NULL;
    }
    return tmp;

}

struct Driver *
addDriverScore(struct Driver *list, char *driverName, char *raceName, char *date, char *time, int position,
               int differenceInPosition) {
    if (list != NULL) {
        struct Driver *tmp = getDriver(list, driverName);

        tmp->score = addScore(tmp->score, raceName, date, time, position, differenceInPosition);

    } else {
        list = addDriver(list, driverName);
        list->score = addScore(list->score, raceName, date, time, position, differenceInPosition);

    }
    return list;
}

void deleteDriverList(struct Driver *list){
    struct Driver *tmp;

        while(list!=NULL){
            tmp=list;
            list=list->next;
            if(tmp->score !=NULL) deleteScores(tmp->score);
            free(tmp);
        }

}