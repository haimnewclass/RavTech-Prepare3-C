#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*operation_func)(int);  // פונקציית מצביע

int square(int x) {
    return x * x;
}

int increment(int x) {
    return x + 1;
}

int* generateArray(int size, operation_func op) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = op(i);  // שימוש במצביע לפונקציה
    }

    return arr;
}

void printArray(int* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void process(int size) {
    operation_func ops[2] = { square, increment };

    for (int i = 0; i < 2; i++) {
        int* data = generateArray(size, ops[i]);
        printArray(data, size);

    }
}

int main() {
    char arr[10];
    for (size_t i = 0; i < 10000; i++)
    {
		arr[i] = 'a';
        printf("%d \n", i);
    }

    for (int i = 1; i <= 5; i++) {
        printf("Processing array of size %d\n", i * 3);
        process(i * 3);
    }

    return 0;
}
