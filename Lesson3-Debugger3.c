#include <stdio.h>
#include <stdlib.h>

int find_max(int* arr, int size) {
    int max = arr[0];
    for (int i = 0; i <= size; i++) {  // ❗ באג לוגי: צריך להיות i < size
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int find_min(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void fill_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 3) * 5;  // 15, 20, 25, ...
    }
}

void analyze_array(int* arr, int size) {
    int max = find_max(arr, size);
    int min = find_min(arr, size);

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
}

int main3() {
    int size = 6;
    int* numbers = (int*)malloc(size * sizeof(int));
    if (!numbers) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fill_array(numbers, size);
    analyze_array(numbers, size);

    free(numbers);
    return 0;
}
