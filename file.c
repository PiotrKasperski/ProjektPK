//
// Created by klonek on 22.05.19.
//
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "driver.h"

struct Driver *loadDataFromFile(char *fileName, struct Driver *list) {
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
            int position = atoi(strtok(result, ", "));
            char *driverName = strtok(NULL, ",");
            deleteLast(driverName, '\n');
            deleteFirst(driverName);
            int startPosition = atoi(strtok(NULL, ", "));
            char *time = strtok(NULL, ", ");
            deleteLast(time, '\n');

            list = addDriverScore(list, driverName, raceName, date, time, position, startPosition - position);

        }
    }
    fclose(file);
    return list;
}

void deleteLast(char *str, const char ch) {
    int len = strlen(str);
    char *ptr = str + (len - 1);
    while (*ptr == ch) *ptr-- = '\0';
}

void deleteFirst(char *str) {
    int len = strlen(str), i = 0;
    if (str[0] == ' ') {
        while (i <= len || str[i] == '\0') {
            str[i] = str[i + 1];
            i++;

        }
    }

}
char *getSign(int i){
    if (i>0) return "+";
    return "";
}

void saveDriverResultToFile(struct Driver *list) {
    FILE *file;
    char *filename;
    filename = (char*)malloc(sizeof(char)*255);
    char *sign;
    sign = (char*)malloc(sizeof(char));
    strcpy(filename, list->name);
    strcat(filename, ".txt");
    if ((file = fopen(filename, "w+t")) == NULL) {
        printf("Blad otwarcia pliku");
    } else {
        fprintf(file, "%s\n", list->name);
        if (list->score != NULL)
            sign =getSign(list->score->differenceInPosition);
            fprintf(file, "%s %s %s %d %s%d\n", list->score->date, list->score->raceName, list->score->time,
                    list->score->position, sign,list->score->differenceInPosition);
        while (list->score->next != NULL) {
            sign =getSign(list->score->next->differenceInPosition);
            fprintf(file, "%s %s %s %d %s%d\n", list->score->next->date, list->score->next->raceName,
                    list->score->next->time, list->score->next->position,sign,list->score->next->differenceInPosition);
            list->score = list->score->next;
        }
    }
    fclose(file);
};
void saveDriverList(struct Driver *list){
    if(list!=NULL){
        saveDriverResultToFile(list);
        while (list->next!=NULL) {
            saveDriverResultToFile(list->next);
            list = list->next;

        }
    }
}