// Program to count total, leaf, and internal nodes of a tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countTotal(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

int countLeaf(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countInternal(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Total nodes: %d\n", countTotal(root));
    printf("Leaf nodes: %d\n", countLeaf(root));
    printf("Internal nodes: %d\n", countInternal(root));

    return 0;
}