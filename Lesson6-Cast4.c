#include <stdio.h>

int main() {
    int x = 65;
    void* ptr = &x;
    char* cptr = ptr;

    printf("Value: %c\n", *cptr);
    return 0;
}
