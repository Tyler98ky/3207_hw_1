#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "main.h"
#include "Config.h"
#include "PriorityQueue.h"

int CURRENT_TIME = 0;
FILE *logFile;
int EVENT_COUNTER = 1;
int JOB_COUNTER = 1;
PriorityQueueNode* EVENT_QUEUE;


int main() {
    /* Perform initial setup by parsing the "Config.txt" file, then creating a log file "log.txt", and then
     * append the current config that was just parsed to the log file
     * */
    initializeConfig("Config.txt");
    srand(SEED);
    createLogFile();

    // Initialize the priority queue with the first and last events
    char* eventDescriptionBuffer;
    eventDescriptionBuffer = malloc(sizeof(char) * 255);
    sprintf(eventDescriptionBuffer, "Job arrived");
    enum Events initEventType = NEW_CPU_EVENT;
    EVENT_QUEUE = newNode(eventDescriptionBuffer, INIT_TIME, initEventType);

    enum Events finEventType = EVENT_FINISHED_EVENT;
    eventDescriptionBuffer = malloc(sizeof(char) * 255);
    sprintf(eventDescriptionBuffer, "Simulation finished");
    push(&EVENT_QUEUE, eventDescriptionBuffer, FIN_TIME, finEventType);

    while (CURRENT_TIME <= FIN_TIME) {
        CURRENT_TIME = EVENT_QUEUE->arrivalTime;
        const char* event = EVENT_QUEUE->eventDescription;
        enum Events currentEventType = EVENT_QUEUE->eventType;

        char* logMessageBuffer = malloc(sizeof(char) * 255);
        sprintf(logMessageBuffer, "%d. %s when CURRENT_TIME = %d\n", EVENT_COUNTER++, event, CURRENT_TIME);
        logMessage(logMessageBuffer);

        int lengthOfProcess = determineProcessLength(currentEventType);
        if (lengthOfProcess != -1) {
            char* newEventName = malloc(sizeof(char) * 255);
            int newArrivalTime = CURRENT_TIME + lengthOfProcess;
            enum Events newEventType = EVENT_FINISHED_EVENT;

            strcpy(newEventName, stringFromEventsEnum(newEventType));
            push(&EVENT_QUEUE, newEventName, newArrivalTime, newEventType);
        }


        PriorityQueueNode temp;
        temp.eventType = getRandomEventType();
        temp.eventDescription = stringFromEventsEnum(temp.eventType);
        temp.arrivalTime = CURRENT_TIME + generateWaitTime();


        /*char* evenNewerEventName = malloc(sizeof(char) * 255);
        enum Events evenNewerEventType = NEW_CPU_EVENT;
        int evenNewerArrivalTime = CURRENT_TIME + generateWaitTime();
        strcpy(evenNewerEventName, stringFromEventsEnum(evenNewerEventType));*/

        push(&EVENT_QUEUE, temp.eventDescription, temp.arrivalTime, temp.eventType);

        pop(&EVENT_QUEUE);

        //TODO Get next arrival time and add a new event

    }

    closeLogFile();
    return 0;
}

void closeLogFile() {
    fputs("**********SIMULATION FINISHED*********\n", logFile);
    fclose(logFile);
}

void createLogFile() {
    time_t     now;
    struct tm *ts;
    char       buf[80];

    /* Get the current time */
    now = time(NULL);

    /* Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz" */
    ts = localtime(&now);
    strftime(buf, sizeof(buf), "---------%Y-%m-%d-%H:%M:%S-%Z---------\n", ts);

    logFile = fopen("log.txt", "w+");
    fputs("*********STARTING A NEW SIMULATION*********\n", logFile);
    fputs(buf, logFile);
    fputs(getCurrentConfig(), logFile);
    fputs("-------------------------\n", logFile);
}

void logMessage(char *message) {
    fputs(message, logFile);
}

// Get an int for next arrival time within the range inclusive
int determineProcessLength(enum Events eventType) {
    switch (eventType) {
        case NEW_CPU_EVENT:
            if (shouldQuit()) {
                return 0;
            }
            return ((int)rand()) % (CPU_MAX - CPU_MIN + 1) + CPU_MIN;
        case NEW_DISK_1_EVENT:
            return ((int)rand()) % (DISK1_MAX - DISK1_MIN + 1) + DISK1_MIN;
        case NEW_DISK_2_EVENT:
            return ((int)rand()) % (DISK2_MAX - DISK2_MIN + 1) + DISK2_MIN;
        case EVENT_FINISHED_EVENT:
            return -1;
        default:
            return -1;
    }
}

int shouldQuit() {
    int randomNumber = ((int)rand()) % 100;
    if (randomNumber <= QUIT_PROB)
        return 1;
    return 0;
}

int generateWaitTime() {
    return ((int)rand()) % (ARRIVE_MAX - ARRIVE_MIN + 1) + ARRIVE_MIN;
}