#include <stdio.h>

void printArray(void* arr, int size) {
    int* intArr = (int*)arr;
    for (int i = 0; i < size; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = { 1.1, 2.2, 3.3 };
    printArray(arr, 3);
    return 0;
}
