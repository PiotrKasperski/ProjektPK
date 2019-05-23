//
// Created by klonek on 22.05.19.
//

#ifndef PROJEKT_FILE_H
#define PROJEKT_FILE_H

#include <stdio.h>
#include <malloc.h>

struct Driver *loadDataFromFile(char * fileName, struct Driver *list);
void savedriverResultToFile(struct Driver *list);
void saveDriverList(struct Driver *list);

void deleteLast(char *str, const char ch);
void deleteFirst(char *str);
char *getSign(int i);
#endif //PROJEKT_FILE_H
