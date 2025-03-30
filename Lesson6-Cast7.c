#include <stdio.h>

typedef struct {
    int x;
    float y;
} A;

typedef struct {
    float y;
    int x;
} B;

int main() {
    A a = { 10, 3.5 };
    B* b = (B*)&a;

    printf("X: %d, Y: %.2f\n", b->x, b->y);
    return 0;
}
