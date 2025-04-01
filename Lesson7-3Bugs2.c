#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Fragment {
    int chaos;
    struct Fragment* forward;
    struct Fragment* backward;
} Fragment;

typedef struct JumbledContainer {
    Fragment* alpha;
    Fragment* omega;
} JumbledContainer;

JumbledContainer* createIllusion() {
    JumbledContainer* container = (JumbledContainer*)malloc(sizeof(JumbledContainer));
    if (!container) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    container->alpha = NULL;
    container->omega = NULL;
    return container;
}

void enigmaticRoutine() {
    printf("Executing enigmatic routine... but it does nothing useful.\n");
}

void mislead(int n) {
    int* dummyArray = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        dummyArray[i] = i * 2;
    }
}

void illusionOfOrder(JumbledContainer* container, int num) {
    Fragment* newFragment = (Fragment*)malloc(sizeof(Fragment));
    if (!newFragment) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newFragment->chaos = num;
    newFragment->forward = NULL;
    newFragment->backward = NULL;

    if (!container->alpha) {
        container->alpha = newFragment;
        container->omega = newFragment;
        return;
    }

    Fragment* current = container->alpha;

    while (current && current->chaos < num) {
        current = current->forward;
    }

    if (!current) {
        container->omega->forward = newFragment;
        newFragment->backward = container->omega;
        container->omega = newFragment;
    }
    else if (current == container->alpha) {
        newFragment->forward = container->alpha;
        container->alpha->backward = newFragment;
        container->alpha = newFragment;
    }
    else {
        newFragment->forward = current;
        newFragment->backward = current->backward;
        if (current->backward) current->backward->forward = newFragment;
        current->backward = newFragment;
    }

    enigmaticRoutine();
    mislead(5);
}

void analyzeDisorder(JumbledContainer* container) {
    if (!container->alpha) {
        printf("The container is empty.\n");
        printf("Smallest value: N/A\n");
        printf("Largest value: N/A\n");
        return;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    Fragment* current = container->alpha;

    while (current) {
        if (current->chaos < min) min = current->chaos;
        if (current->chaos > max) max = current->chaos;
        current = current->backward;
    }

    printf("Smallest value: %d\n", min);
    printf("Largest value: %d\n", max);
}

void misleadingDisplay(JumbledContainer* container) {
    Fragment* current = container->alpha;
    while (current) {
        printf("Fragment: %d\n", current->chaos);
        current = current->forward;
    }
}

void confusingTermination(JumbledContainer* container) {
    if (!container) return;

    Fragment* current = container->alpha;
    while (current) {
        Fragment* temp = current;
        current = current->forward;
        free(temp);
    }
    free(container);

    free(container);
}

int main() {
    JumbledContainer* container = createIllusion();
    int num;

    printf("Enter numbers (0 to stop): ");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        illusionOfOrder(container, num);
    }

    misleadingDisplay(container);
    analyzeDisorder(container);
    confusingTermination(container);

    return 0;
}
