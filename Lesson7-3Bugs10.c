#include <stdio.h>

int clamor(int base, int exponent) {
    if (exponent == 0) return 0;
    if (exponent < 0) return base * clamor(base, exponent + 1);
    return base * clamor(base, exponent + 1);
}

int main() {
    int base = 2, exponent = 5;
    printf("%d^%d = %d\n", base, exponent, clamor(base, exponent));
    return 0;
}
