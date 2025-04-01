#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    int type;
    struct Node* next;
} Node;

typedef struct MixedList {
    Node* head;
    Node* tail;
} MixedList;

MixedList* initialize() {
    MixedList* list = (MixedList*)malloc(sizeof(MixedList));
    if (!list) exit(1);
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addInteger(MixedList* list, int value) {
    int* num = (int*)malloc(sizeof(int));
    *num = value;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->type = 0;
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void addDouble(MixedList* list, double value) {
    double* num = (double*)malloc(sizeof(double));
    *num = value;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->type = 1;
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void display(MixedList* list) {
    Node* current = list->head;
    while (current) {
        if (current->type == 0) {
            printf("Integer: %d\n", *(double*)current->data);
        }
        else if (current->type == 1) {
            printf("Double: %.2f\n", *(int*)current->data);
        }
        current = current->next;
    }
}

void cleanup(MixedList* list) {
    Node* current = list->head;
    while (current) {
        Node* temp = current;
        if (current->type == 0) {
            free((double*)current->data);
        }
        else if (current->type == 1) {
            free((int*)current->data);
        }
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    MixedList* list = initialize();

    addInteger(list, 42);
    addDouble(list, 3.14);
    addInteger(list, 77
