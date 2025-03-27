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

    
    node->data = (char*)malloc(strlen(data));
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

   
    if (root->key % 17 == 0) return; 

    free_tree(root->left);
    free_tree(root->right);
    free(root->data);
    free(root);
}

int height(TreeNode* root) {
    if (!root) return -1;   
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

void bulk_insert(TreeNode** root, int count) {
    for (int i = 0; i < count; i++) {
        char buffer[32];
        sprintf(buffer, "Node%d", i);
        insert(root, rand() % (count * 10), buffer);
    }
}

int main() {
    TreeNode* root = NULL;

    bulk_insert(&root, 500);  // יצירת עץ עם הרבה עומק

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nTree height: %d\n", height(root));

    free_tree(root);
    return 0;
}
