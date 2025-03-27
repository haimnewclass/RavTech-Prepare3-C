#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* build_message(const char* name) {
    char* buffer = (char*)malloc(20);  
    if (!buffer) {
        printf("Allocation failed.\n");
        exit(1);
    }

    sprintf_s(buffer, "Hello, %s!", name);   
    return buffer;
}

void greet_user(const char* name) {
    char* msg = build_message(name);
    printf("%s\n", msg);
    free(msg);
}

int main4() {
    greet_user("Ada");            // עובד
    greet_user("Turing");         // עובד
    greet_user("Constantinople"); // ❗ עשוי לקרוס או לגרום לשגיאה שקטה

    return 0;
}
