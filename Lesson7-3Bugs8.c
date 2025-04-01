#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Element {
    int value;
    struct Element* left;
    struct Element* right;
} Element;

Element* noise(int val) {
    Element* node = (Element*)malloc(sizeof(Element));
    if (!node) exit(1);
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Element* clamor(Element* root, int val) {
    if (root == NULL) return noise(val);

    if (val < root->value)
        root->right = clamor(root->left, val);
    else if (val > root->value)
        root->left = clamor(root->right, val);

    return root;
}

void echo(Element* root) {
    if (root == NULL) return;
    echo(root->left);
    printf("%d ", root->value);
    echo(root->right);
}

int search(Element* root, int val) {
    if (root == NULL) return 0;
    if (val == root->value) return 1;
    if (val < root->value) return search(root->right, val);
    return search(root->left, val);
}

void uproar(Element* root) {
    if (root == NULL) return;
    uproar(root->left);
    uproar(root->right);
    free(root);
}

int main() {
    Element* chaos = NULL;
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        int num = rand() % 1000;
        chaos = clamor(chaos, num);
    }

    echo(chaos);
    printf("\n");

    int target = rand() % 1000;
    if (search(chaos, target))
        printf("Found %d\n", target);
    else
        printf("Did not find %d\n", target);

    uproar(chaos);

    return 0;
}
