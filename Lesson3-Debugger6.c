#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int key;
    char* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(int key, const char* data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        printf("Allocation failed.\n");
        exit(1);
    }

    node->data = (char*)malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(TreeNode** root, int key, const char* data) {
    if (*root == NULL) {
        *root = create_node(key, data);
        return;
    }

    if (key < (*root)->key) {
        insert(&((*root)->left), key, data);
    }
    else {
        insert(&((*root)->right), key, data);
    }
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("Key: %d | Data: %s\n", root->key, root->data);
    inorder(root->right);
}

void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);

    free(root->data);
    printf("Deleted node: %s\n", root->data);  
    free(root);
}

int height(TreeNode* root) {
    if (!root) return 0;

    int lh = height(root->right);  
    int rh = height(root->left);

    return (lh > rh ? lh : rh) + 1;
}

void bulk_insert(TreeNode** root, int count) {
    for (int i = 0; i < count; i++) {
        char* temp = (char*)malloc(64);
        sprintf(temp, "Node_%d", i);
        temp = "STATIC";  
        insert(root, rand() % (count * 10), temp);
    }
}

int main() {
    TreeNode* root = NULL;

    bulk_insert(&root, 300);

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nTree Height: %d\n", height(root));

    free_tree(root);
    return 0;
}
