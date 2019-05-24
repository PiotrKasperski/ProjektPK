//
// Created by klonek on 22.05.19.
//

#include "driver.h"

static Driver *getDriver(Driver *list, char *driverName) {
    if (list != NULL) {
        if (strcmp(list->name, driverName) == 0) return list;
        while (list->next != NULL) {
            if (strcmp(list->next->name, driverName) == 0) return list->next;
            list = list->next;
        }
        list->next = (Driver *) malloc(sizeof(Driver));
        list->next->next = NULL;
        list->next->name = driverName;
        list->next->score = NULL;
        return list->next;
    } else {
        Driver *tmp = (Driver *) malloc(sizeof(Driver));
        tmp->name = driverName;
        tmp->score = NULL;
        tmp->next = NULL;
        return tmp;
    }
}

static Driver *addDriver(Driver *list, char *driverName) {
    if (list != NULL) {
        if (strcmp(list->name, driverName) == 0) return list;
        while (list->next != NULL) {
            if (strcmp(list->name, driverName) == 0) return list;
            list = list->next;
        }
        list->next = (Driver *) malloc(sizeof(Driver));
        list->next->next = NULL;
        list->next->name = driverName;
        list->next->score = NULL;
    } else {
        Driver *tmp = (Driver *) malloc(sizeof(Driver));
        tmp->name = driverName;
        tmp->score = NULL;
        tmp->next = NULL;
        return tmp;
    }
    return list;
}

Driver *
addDriverScore(Driver *list, char *driverName, char *raceName, char *date, char *time, int position,
               int differenceInPosition) {
    if (list != NULL) {
        Driver *tmp = getDriver(list, driverName);
        tmp->score = addScore(tmp->score, raceName, date, time, position, differenceInPosition);
    } else {
        list = addDriver(list, driverName);
        list->score = addScore(list->score, raceName, date, time, position, differenceInPosition);
    }
    return list;
}

void deleteDriverList(Driver *list) {
        while(list!=NULL){
            Driver *tmp;
            tmp=list;
            list=list->next;
            if(tmp->score !=NULL) deleteScores(tmp->score);
            free(tmp);
        }

}

void deleteLast(char *str, const char ch) {
    if (str != NULL) {
        int lenght = (int) strlen(str);
        char *ptr = str + (lenght - 1);
        while (*ptr == ch) *ptr-- = '\0';
    }

}

static void deleteFirst(char *str) {
    if (str != NULL) {
        int lenght = (int) strlen(str);
        if (str[0] == ' ') {
            int i = 0;
            while (i <= lenght || str[i] == '\0') {
                str[i] = str[i + 1];
                i++;
            }
        }
    }
}

Driver *saveResults(char *result, char *raceName, char *date, Driver *list) {
    if (strcmp(result, "") != 0 && strcmp(result, "\n") != 0) {
        char *pos = strtok(result, ", ");
        char *driverName = strtok(NULL, ",");
        char *startPos = strtok(NULL, ", ");
        char *time = strtok(NULL, ", ");
        if (pos != NULL && driverName != NULL && startPos != NULL && time != NULL) {
            int position = (int) strtol(pos, NULL, 10);
            int startPosition = (int) strtol(startPos, NULL, 10);
            deleteLast(driverName, '\n');
            deleteFirst(driverName);
            deleteLast(time, '\n');
            return addDriverScore(list, driverName, raceName, date, time, position, startPosition - position);
        } else return list;

    }
    return list;
}