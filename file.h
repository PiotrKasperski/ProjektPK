//
// Created by klonek on 22.05.19.
//

#ifndef PROJEKT_FILE_H
#define PROJEKT_FILE_H

#include <stdio.h>
#include <malloc.h>
#include "driver.h"

Driver *loadDataFromFile(char *fileName, Driver *list);

void saveDriverList(Driver *list);

#endif //PROJEKT_FILE_H
