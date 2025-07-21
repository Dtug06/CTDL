#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int main(void) {
    int value;
    printf("Nhap gia tri data\t\n");
    scanf("%d", &value);
    Node *root = createNode(value);
    Node*one=createNode(value);
    Node*two=createNode(value);
    Node*three=createNode(value);
    Node*four=createNode(value);

    root->left=one;
    root->right=two;
    root->left->left=three;
    root->left->right=four;
    return 0;
}