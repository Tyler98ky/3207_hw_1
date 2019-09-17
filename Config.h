//
// Created by Tyler Howard on 9/16/19.
//

#ifndef INC_3207_HW_1_CONFIG_H
#define INC_3207_HW_1_CONFIG_H

int SEED;
int INIT_TIME;
int FIN_TIME;
int ARRIVE_MIN;
int ARRIVE_MAX;
int QUIT_PROB;
int CPU_MIN;
int CPU_MAX;
int DISK1_MIN;
int DISK1_MAX;
int DISK2_MIN;
int DISK2_MAX;

void initializeConfig(char*);
char* getCurrentConfig(void);

#endif //INC_3207_HW_1_CONFIG_H
