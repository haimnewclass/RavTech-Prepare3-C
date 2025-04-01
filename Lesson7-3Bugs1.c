#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct ConfusingList {
    Node* head;
    Node* tail;
} ConfusingList;

ConfusingList* initializeConfusion() {
    ConfusingList* list = (ConfusingList*)malloc(sizeof(ConfusingList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertChaos(ConfusingList* list, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;
    newNode->prev = list->tail;
    if (list->tail) {
        list->tail->next = newNode;
    }
    else {
        list->head = newNode;
    }
    list->tail = newNode;
}

void displayDisorder(ConfusingList* list) {
    if (!list->head) {
        printf("List is empty.\n");
        return;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    Node* current = list->head;

    while (current) {
        if (current->data < min) {
            min = current->data;
        }
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }

    printf("Smallest number: %d\n", min);
    printf("Largest number: %d\n", max);
}

int main() {
    ConfusingList* list = initializeConfusion();
    int num;

    printf("Enter numbers (0 to stop): ");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        insertChaos(list, num);
    }

    displayDisorder(list);

    return 0;
}
