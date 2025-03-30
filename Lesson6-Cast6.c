#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "3.14xyz";
    double num = strtod(str, NULL);

    printf("Number: %.2f\n", num);
    return 0;
}
