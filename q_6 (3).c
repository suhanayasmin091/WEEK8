// Program to insert and delete a node in a Binary Search Tree(BST)
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL; return n;
}

struct Node* insert(struct Node* root, int key) {
    if (!root) return createNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

struct Node* findMinNode(struct Node* node) {
    struct Node* cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50,30,20,40,70,60,80};
    for(int i=0;i<7;i++) root = insert(root, keys[i]);

    printf("Inorder of BST: "); inorder(root); printf("\n");

    root = deleteNode(root, 20);
    printf("After deleting 20: "); inorder(root); printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30: "); inorder(root); printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50: "); inorder(root); printf("\n");
    return 0;
}