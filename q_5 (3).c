// Program to search for an element in a binary tree
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

int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;  
    if (root->data == key)
        return 1;   
    return search(root->left, key) || search(root->right, key);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d not found in the tree.\n", key);

    return 0;
}
