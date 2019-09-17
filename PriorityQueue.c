//
// Created by Tyler Howard on 9/17/19.
//

#include "PriorityQueue.h"

// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>

// Function to Create A New Node
PriorityQueueNode* newNode(char* eventDescription, int arrivalTime, enum Events eventType) {
    PriorityQueueNode* temp = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    temp->eventDescription = eventDescription;
    temp->arrivalTime = arrivalTime;
    temp->eventType = eventType;
    temp->next = NULL;

    return temp;
}

// Return the value at head
char* peek(PriorityQueueNode** head) {
    return (*head)->eventDescription;
}

// Removes the element with the
// highest priority form the list
void pop(PriorityQueueNode** head) {
    PriorityQueueNode* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to push according to priority
void push(PriorityQueueNode** head, char* eventDescription, int arrivalTime, enum Events eventType) {
    PriorityQueueNode* start = (*head);

    // Create new Node
    PriorityQueueNode* temp = newNode(eventDescription, arrivalTime, eventType);

    // Special Case: The head of list has lesser
    // priority than new PriorityQueueNode. So insert new
    // PriorityQueueNode before head PriorityQueueNode and change head PriorityQueueNode.
    if ((*head)->arrivalTime > arrivalTime) {

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // Traverse the list and find a
        // position to insert new PriorityQueueNode
        while (start->next != NULL &&
               start->next->arrivalTime < arrivalTime) {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(PriorityQueueNode** head) {
    return (*head) == NULL;
}

int getEventType(PriorityQueueNode** head) {
    return (*head)->eventType;
}

const char* stringFromEventsEnum(enum Events eventType) {
    return strings[eventType];
}

enum Events getRandomEventType() {
    size_t stringsLength = sizeof(strings)/ sizeof(strings[0]);
    int randomIndex = ((int)rand()) % (stringsLength -1);
    return eventArray[randomIndex];
}

//// Driver code
//int main()
//{
//    // Create a Priority Queue
//    // 7->4->5->6
//    Node* pq = newNode(4, 1);
//    push(&pq, 5, 2);
//    push(&pq, 6, 3);
//    push(&pq, 7, 0);
//
//    while (!isEmpty(&pq)) {
//        printf("%d ", peek(&pq));
//        pop(&pq);
//    }
//
//    return 0;
//}
