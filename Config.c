//
// Created by Tyler Howard on 9/16/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Config.h"


const int NUMBER_OF_CONFIG_PROPERTIES = 12;
const int SEED_INDEX = 0;
const int INIT_TIME_INDEX = 1;
const int FIN_TIME_INDEX = 2;
const int ARRIVE_MIN_INDEX = 3;
const int ARRIVE_MAX_INDEX = 4;
const int QUIT_PROB_INDEX = 5;
const int CPU_MIN_INDEX = 6;
const int CPU_MAX_INDEX = 7;
const int DISK1_MIN_INDEX = 8;
const int DISK1_MAX_INDEX = 9;
const int DISK2_MIN_INDEX = 10;
const int DISK2_MAX_INDEX = 11;



int configValues[NUMBER_OF_CONFIG_PROPERTIES] = {-1 };
char *configNames[NUMBER_OF_CONFIG_PROPERTIES] = {-1 };

void initializeConfig (char* configFileName) {
    FILE *configTextFile = fopen(configFileName, "r");
    int index = 0;
    char buffer[255];
    int value;

    while (fscanf(configTextFile, "%s %d", buffer, &value) != EOF) {
        char *name = malloc(sizeof(char) * 255);
        strcpy(name, buffer);
        configNames[index] = name;
        configValues[index] = value;
        index++;
    }

    SEED = configValues[SEED_INDEX];
    INIT_TIME = configValues[INIT_TIME_INDEX];
    FIN_TIME = configValues[FIN_TIME_INDEX];
    ARRIVE_MIN = configValues[ARRIVE_MIN_INDEX];
    ARRIVE_MAX = configValues[ARRIVE_MAX_INDEX];
    QUIT_PROB = configValues[QUIT_PROB_INDEX];
    CPU_MIN = configValues[CPU_MIN_INDEX];
    CPU_MAX = configValues[CPU_MAX_INDEX];
    DISK1_MIN = configValues[DISK1_MIN_INDEX];
    DISK1_MAX = configValues[DISK1_MAX_INDEX];
    DISK2_MIN = configValues[DISK2_MIN_INDEX];
    DISK2_MAX = configValues[DISK2_MAX_INDEX];

}


char* getCurrentConfig() {
    size_t size = 5000;
    char *buffer = calloc(size, sizeof(char));
    if (configNames[0] == -1) return "No Config found";

    for (size_t i=0; i < sizeof(configNames)/ sizeof(configNames[0]); i++) {
        char currentLine[255];
        sprintf(currentLine, "%s %d\n", configNames[i], configValues[i]);
        strcat(buffer, currentLine);
    }

    return buffer;
}
