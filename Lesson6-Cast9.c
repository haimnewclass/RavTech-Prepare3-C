#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int arr[2] = { 10, 20 };
    Point p;

    memcpy(&p, arr, sizeof(arr));

    printf("X: %d, Y: %d\n", p.x, p.y);
    return 0;
}
