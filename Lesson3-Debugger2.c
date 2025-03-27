#include <stdio.h>
#include <stdlib.h>

int calculate_sum(int* arr, int size) {
    int sum = 0;
    for (int i = 1; i < size; i++) {  // ❗ באג לוגי: מתחיל מ־1 במקום מ־0
        sum += arr[i];
    }
    return sum;
}

double calculate_average(int* arr, int size) {
    int total = calculate_sum(arr, size);
    return (double)total / size;
}

void fill_array3(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;  // 10, 20, 30, ...
    }
}

void print_array(int* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void analyze_array2(int* arr, int size) {
    print_array(arr, size);
    double avg = calculate_average(arr, size);
    printf("Average value: %.2f\n", avg);
}

int main2() {
    int size = 5;
    int* my_array = (int*)malloc(size * sizeof(int));
    if (!my_array) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fill_array3(my_array, size);
    analyze_array2(my_array, size);

    free(my_array);
    return 0;
}
