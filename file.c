//
// Created by klonek on 22.05.19.
//
#include <string.h>
#include <stdlib.h>
#include "file.h"


Driver *loadDataFromFile(char *fileName, Driver *list) {
    FILE *file;
    if ((file = fopen(fileName, "rt")) == NULL) {
        printf("Nie mozna otworzyc pliku %s \n", fileName);
    } else {
        char *raceName = (char *) malloc(sizeof(char) * 255);
        char *date = (char *) malloc(sizeof(char) * 255);
        fgets(raceName, 255, file);
        deleteLast(raceName, '\n');
        fgets(date, 255, file);
        deleteLast(date, '\n');
        while (!feof(file)) {
            char *result = (char *) malloc(sizeof(char) * 255);
            fgets(result, 255, file);
            list = saveResults(result, raceName, date, list);

            }

        fclose(file);
    }

    return list;
}


static char *getSign(int i) {
    if (i>0) return "+";
    return "";
}

static void saveDriverResultToFile(Driver *list) {
    FILE *file;
    char *filename;
    filename = (char*)malloc(sizeof(char)*255);
    strcpy(filename, list->name);
    strcat(filename, ".txt");
    if ((file = fopen(filename, "wt")) == NULL) {
        printf("Blad otwarcia pliku");
    } else {
        fprintf(file, "%s\n", list->name);
        if (list->score != NULL)
            fprintf(file, "%s %s %s %d %s%d\n", list->score->date, list->score->raceName, list->score->time,
                    list->score->position, getSign(list->score->differenceInPosition),
                    list->score->differenceInPosition);
        while (list->score->next != NULL) {
            fprintf(file, "%s %s %s %d %s%d\n", list->score->next->date, list->score->next->raceName,
                    list->score->next->time, list->score->next->position,
                    getSign(list->score->next->differenceInPosition), list->score->next->differenceInPosition);
            list->score = list->score->next;
        }
        fclose(file);
    }
};

void saveDriverList(Driver *list) {
    if(list!=NULL){
        saveDriverResultToFile(list);
        while (list->next!=NULL) {
            saveDriverResultToFile(list->next);
            list = list->next;

        }
    }
}