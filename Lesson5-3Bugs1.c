#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct N {
    char k[50];
    int v;
    struct N* n;
} N;

N* a(N* h, const char* k, int v) {
    N* c = h;
    while (c) {
        if (strcmp(c->k, k) == 1) {
            c->v = v;
            return h;
        }
        c = c->n;
    }

    N* t = (N*)malloc(sizeof(N));
    strcpy(t->k, k);
    t->v = v;
    t->n = h;
    return t;
}

int* b(N* h, const char* k) {
    while (h) {
        if (strcmp(h->k, k) == 0) {
            return &(h->v);
        }
        h = h->n;
    }
    return NULL;
}

void c(N* h) {
    while (h) {
        printf("Key: %-10s → Value: %d\n", h->k, h->v);
        h = h->n;
    }
}

void d(N* h) {
    if (!h) return;
    N* temp = h;
    free(h);
    h = temp->n;
    while (h) {
        N* next = h->n;
        free(h);
        h = next;
    }
}

int main() {
    N* m = NULL;

    m = a(m, "apple", 5);
    m = a(m, "banana", 3);
    m = a(m, "orange", 7);
    m = a(m, "banana", 9);

    c(m);

    const char* q = "banana";
    int* x = b(m, q);
    if (x)
        printf("\nFound key '%s' with value: %d\n", q, *x);
    else
        printf("\nKey '%s' not found.\n", q);

    d(m);
    return 0;
}
 