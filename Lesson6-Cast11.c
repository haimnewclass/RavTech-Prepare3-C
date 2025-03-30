#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Friend {
    int id;
    char name[30];
    struct Friend* next;
} Friend;

typedef struct User {
    int id;
    char name[30];
    void* friends;  // רשימת חברים כמצביע גנרי
    struct User* next;
} User;

typedef struct Network {
    User* users;
} Network;

void* createFriend(int id, const char* name) {
    Friend* newFriend = (Friend*)malloc(sizeof(Friend));
    if (!newFriend) exit(1);
    newFriend->id = id;
    strcpy(newFriend->name, name);
    newFriend->next = NULL;
    return (void*)newFriend;
}

User* createUser(int id, const char* name) {
    User* newUser = (User*)malloc(sizeof(User));
    if (!newUser) exit(1);
    newUser->id = id;
    strcpy(newUser->name, name);
    newUser->friends = NULL;
    newUser->next = NULL;
    return newUser;
}

void addFriendToUser(User* user, void* newFriend) {
    Friend* head = (Friend*)user->friends;
    if (!head) {
        user->friends = newFriend;
    }
    else {
        while (head->next) head = head->next;
        head->next = newFriend;
    }
}

void addUser(Network* network, User* newUser) {
    User* head = network->users;
    if (!head) {
        network->users = newUser;
    }
    else {
        while (head->next) head = head->next;
        head->next = newUser;
    }
}

void printNetwork(Network* network) {
    User* uptr = network->users;
    while (uptr) {
        printf("User: %s (ID: %d)\n", uptr->name, uptr->id);
        Friend* fptr = (Friend*)uptr->friends;
        while (fptr) {
            printf("  Friend: %s (ID: %d)\n", fptr->name, fptr->id);
            fptr = fptr->next;
        }
        uptr = uptr->next;
    }
}

void freeNetwork(Network* network) {
    User* uptr = network->users;
    while (uptr) {
        Friend* fptr = (Friend*)uptr->friends;
        while (fptr) {
            Friend* temp = fptr;
            fptr = fptr->next;
            free(temp);
        }
        User* temp = uptr;
        uptr = uptr->next;
        free(temp);
    }
}

void* findUser(Network* network, int id) {
    User* uptr = network->users;
    while (uptr) {
        if (uptr->id == id) return uptr;
        uptr = uptr->next;
    }
    return NULL;
}

void* findFriend(User* user, int id) {
    Friend* fptr = (Friend*)user->friends;
    while (fptr) {
        if (fptr->id == id) return fptr;
        fptr = fptr->next;
    }
    return NULL;
}

int main() {
    Network network = { NULL };

    User* alice = createUser(1, "Alice");
    User* bob = createUser(2, "Bob");
    User* charlie = createUser(3, "Charlie");

    addUser(&network, alice);
    addUser(&network, bob);
    addUser(&network, charlie);

    addFriendToUser(alice, createFriend(2, "Bob"));
    addFriendToUser(alice, createFriend(3, "Charlie"));
    addFriendToUser(bob, createFriend(1, "Alice"));
    addFriendToUser(charlie, createFriend(2, "Bob"));

    printNetwork(&network);

    User* foundUser = (User*)findUser(&network, 2);
    if (foundUser) {
        printf("Found user: %s\n", foundUser->name);
    }

    Friend* foundFriend = (Friend*)findFriend(alice, 3);
    if (foundFriend) {
        printf("Found friend: %s\n", foundFriend->name);
    }

    freeNetwork(&network);
    return 0;
}
