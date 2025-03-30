#include <stdio.h>

void hello() {
    printf("Hello!\n");
}

int main() {
    void* ptr = hello;
    void (*func)() = ptr;

    func();
    return 0;
}
