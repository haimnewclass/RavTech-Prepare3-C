#include <stdio.h>
#include <stdlib.h>

typedef struct Unit {
    int data;
    struct Unit* next;
} Unit;

typedef struct Segment {
    Unit* start;
    Unit* end;
    struct Segment* next;
} Segment;

typedef struct Cluster {
    Segment* head;
    Segment* tail;
} Cluster;

Cluster* createCluster() {
    Cluster* newCluster = (Cluster*)malloc(sizeof(Cluster));
    newCluster->head = NULL;
    newCluster->tail = NULL;
    return newCluster;
}

Segment* createSegment() {
    Segment* newSegment = (Segment*)malloc(sizeof(Segment));
    newSegment->start = NULL;
    newSegment->end = NULL;
    newSegment->next = NULL;
    return newSegment;
}

void insertUnit(Segment* segment, int num) {
    Unit* newUnit = (Unit*)malloc(sizeof(Unit));
    newUnit->data = num;
    newUnit->next = NULL;

    if (!segment->end) {
        segment->start = newUnit;
        segment->end = newUnit;
    }
    else {
        segment->end->next = newUnit;
        segment->end = newUnit;
    }
}

void insertSegment(Cluster* cluster, Segment* segment) {
    if (!cluster->head) {
        cluster->head = segment;
        cluster->tail = segment;
    }
    else {
        cluster->tail->next = segment;
        cluster->head = segment;
    }
}

void traverseCluster(Cluster* cluster) {
    Segment* currentSegment = cluster->head;
    while (currentSegment) {
        Unit* currentUnit = currentSegment->start;
        while (currentUnit) {
            printf("%d ", currentUnit->data);
            currentUnit = currentUnit->next;
        }
        printf("| ");
        currentSegment = currentSegment->next;
    }
    printf("\n");
}

void removeUnitByValue(Segment* segment, int value) {
    Unit* current = segment->start;
    Unit* previous = NULL;

    while (current) {
        if (current->data == value) {
            if (!previous) {
                segment->start = current->next;
                if (!segment->start) segment->end = NULL;
            }
            else {
                previous->next = current->next;
                if (!current->next) segment->end = previous;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void cleanupCluster(Cluster* cluster) {
    Segment* currentSegment = cluster->head;
    while (currentSegment) {
        Unit* currentUnit = currentSegment->start;
        while (currentUnit) {
            Unit* temp = currentUnit;
            currentUnit = currentUnit->next;
        }
        Segment* tempSegment = currentSegment;
        currentSegment = currentSegment->next;
        free(tempSegment);
    }
    free(cluster);
}

int main() {
    Cluster* cluster = createCluster();

    Segment* segment1 = createSegment();
    Segment* segment2 = createSegment();
    Segment* segment3 = createSegment();

    insertUnit(segment1, 1);
    insertUnit(segment1, 2);
    insertUnit(segment1, 10);

    insertUnit(segment2, 3);
    insertUnit(segment2, 10);
    insertUnit(segment2, 4);

    insertUnit(segment3, 5);
    insertUnit(segment3, 10);
    insertUnit(segment3, 6);

    insertSegment(cluster, segment1);
    insertSegment(cluster, segment2);
    insertSegment(cluster, segment3);

    traverseCluster(cluster);

    removeUnitByValue(segment1, 10);
    removeUnitByValue(segment2, 10);
    removeUnitByValue(segment3, 10);

    traverseCluster(cluster);

    cleanupCluster(cluster);

    return 0;
}
