//
// Created by Tyler Howard on 9/17/19.
//

#ifndef INC_3207_HW_1_PRIORITYQUEUE_H
#define INC_3207_HW_1_PRIORITYQUEUE_H

enum Events {NEW_CPU_EVENT, NEW_DISK_1_EVENT, NEW_DISK_2_EVENT, EVENT_FINISHED_EVENT};
static const char* strings[] = {"NEW_CPU_EVENT", "NEW_DISK_1_EVENT", "NEW_DISK_2_EVENT", "EVENT_FINISHED_EVENT"};
static const enum Events eventArray[] = {NEW_CPU_EVENT, NEW_DISK_1_EVENT, NEW_DISK_2_EVENT, EVENT_FINISHED_EVENT};

// Node
typedef struct PriorityQueueNode {
    char* eventDescription;

    // Lower values indicate higher priority
    int arrivalTime;

    enum Events eventType;

    struct PriorityQueueNode* next;

} PriorityQueueNode;

PriorityQueueNode* newNode(char* eventDescription, int arrivalTime, enum Events eventType);
char* peek(PriorityQueueNode** head);
void pop(PriorityQueueNode** head);
void push(PriorityQueueNode** head, char* eventDescription, int arrivalTime, enum Events eventType);
int isEmpty(PriorityQueueNode** head);
const char* stringFromEventsEnum(enum Events eventType);

/**
 *
 * @param head
 * @return 0 for new cpu-job, 1 for new Disk1 job, 2 for new Disk2 job, 3 for event finished (including sim_fin)
 */
int getEventType(PriorityQueueNode** head);
enum Events getRandomEventType(void);




#endif //INC_3207_HW_1_PRIORITYQUEUE_H
