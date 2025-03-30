#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float value;
} Point;

int main() {
    Point p = { 1, 5.5 };
    void* ptr = &p;
    Point* p2 = ptr;

    printf("ID: %d, Value: %.2f\n", p2->id, p2->value);
    return 0;
}
