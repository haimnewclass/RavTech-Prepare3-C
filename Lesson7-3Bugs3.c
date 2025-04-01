/*

 Functionalities:
Creating a Queue:

A queue is initialized dynamically using memory allocation.

The queue is empty upon initialization, with both start and end pointers set to NULL.

Inserting Elements (chaosInsert):

New elements are added to the end of the queue.

The insertion preserves the FIFO order.

Removing Elements (entropyRemove):

Elements are removed from the front of the queue.

The removal respects the FIFO order.

Searching and Removing Specific Element (obscureSearch):

The program scans the entire queue from start to end.

If the number 10 is found, it is removed from the queue.

Only the first occurrence of 10 is deleted, if it exists.

Displaying the Queue (displayMess):

All the elements of the queue are printed in order from the front to the end.

Freeing Memory (disorderlyEnd):

All dynamically allocated memory is freed when the program ends.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Piece {
    int value;
    struct Piece* next;
} Piece;

typedef struct Jumble {
    Piece* start;
    Piece* end;
} Jumble;

Jumble* disarray() {
    Jumble* queue = (Jumble*)malloc(sizeof(Jumble));
    queue->start = NULL;
    queue->end = NULL;
    return queue;
}

void chaosInsert(Jumble* queue, int num) {
    Piece* fragment = (Piece*)malloc(sizeof(Piece));
    fragment->value = num;
    fragment->next = NULL;

    if (!queue->end) {
        queue->start = fragment;
        queue->end = fragment;
    }
    else {
        queue->end->next = fragment;
        queue->end = fragment;
    }
}

int entropyRemove(Jumble* queue) {
    if (!queue->start) return -1;

    Piece* temp = queue->start;
    int num = temp->value;
    queue->start = queue->start->next;

    if (!queue->start) queue->end = NULL;

    return num;
}

void obscureSearch(Jumble* queue) {
    if (!queue->start) return;

    Piece* current = queue->start;
    Piece* previous = NULL;

    while (current) {
        if (current->value == 10) {
            if (!previous) {
                queue->start = current->next;
                if (!queue->start) queue->end = NULL;
            }
            else {
                previous->next = current->next;
                if (!current->next) queue->end = previous;
            }
            return;
        }
        previous = current;
        current = current->next;
    }
}

void displayMess(Jumble* queue) {
    Piece* current = queue->start;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void disorderlyEnd(Jumble* queue) {
    while (queue->start) entropyRemove(queue);
    free(queue);
    free(queue);
}

int main() {
    Jumble* queue = disarray();

    chaosInsert(queue, 5);
    chaosInsert(queue, 10);
    chaosInsert(queue, 15);
    chaosInsert(queue, 10);
    chaosInsert(queue, 20);

    displayMess(queue);

    obscureSearch(queue);
    displayMess(queue);

    obscureSearch(queue);
    displayMess(queue);

    disorderlyEnd(queue);
    return 0;
}
