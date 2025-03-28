#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct X {
    char a[50];
    char b[50];
    int v;
    struct X* n;
    struct X* m;
} X;

X* f(X* h, const char* a, const char* b, int v) {
    X* p = h;
    while (p) {
        if (strcmp(p->a, a) == 0) {
            X* q = p;
            while (q) {
                if (strcmp(q->b, b) == 0) {
                    q->v = v;
                    return h;
                }
                if (!q->m) break;
                q = q->m;
            }
            X* z = (X*)malloc(sizeof(X));
            if (!z) exit(1);
            strcpy(z->a, a);
            strcpy(z->b, b);
            z->v = v;
            z->n = h;
            z->m = NULL;
            q->m = z;
            return h;
        }
        p = p->n;
    }

    X* z = (X*)malloc(sizeof(X));
    if (!z) exit(1);
    strcpy(z->a, a);
    strcpy(z->b, b);
    z->v = v;
    z->n = h;
    z->m = NULL;
    return z;
}

X* g(X* h, const char* a) {
    while (h) {
        if (strcmp(h->a, a) == 0) {
            return h;
        }
        h = h->n;
    }
    return NULL;
}

void t(X* x) {
    while (x) {
        printf("A: %-10s | B: %-10s → V: %d\n", x->a, x->b, x->v);
        x = x->m;
    }
}

void r(X* h) {
    while (h) {
        X* q = h->m;
        while (q) {
            X* z = q;
            q = q->m;
            free(z);
        }
        X* z = h;
        h = h->n;
        free(z);
    }
}

int main() {
    X* w = NULL;

    w = f(w, "x", "a", 1);
    w = f(w, "x", "b", 2);
    w = f(w, "x", "c", 3);
    w = f(w, "y", "a", 4);
    w = f(w, "y", "b", 5);

    X* q = g(w, "x");
    if (q) {
        printf("==\n");
        t(q);
    }

    r(w);
    return 0;
}
