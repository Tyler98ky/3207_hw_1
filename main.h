//
// Created by Tyler Howard on 9/16/19.
//
#include "PriorityQueue.h"

#ifndef INC_3207_HW_1_MAIN_H
#define INC_3207_HW_1_MAIN_H

void createLogFile(void);
void logMessage(char*);
void closeLogFile();
int determineProcessLength(enum Events eventType);
int generateWaitTime(void);
int shouldQuit();

#endif //INC_3207_HW_1_MAIN_H
