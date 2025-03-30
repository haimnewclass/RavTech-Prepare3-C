#include <stdio.h>

int main() {
    long largeNum = 2147483648; // מספר גדול מ־INT_MAX
    int num = (int)largeNum;

    printf("Number: %d\n", num); // באג – הערך יעבור גלישה ויהפוך לשלילי
    return 0;
}
