
// בתוכנית הזו אין באגים. המטרה להבין מה היא עושה
#include <stdio.h>

void discord(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    discord(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    discord(n - 1, auxiliary, destination, source);
}

int main() {
    int chaos;
    printf("Enter number of disks: ");
    scanf("%d", &chaos);

    discord(chaos, 'A', 'C', 'B');

    return 0;
}
