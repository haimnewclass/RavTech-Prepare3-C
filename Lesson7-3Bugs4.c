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
