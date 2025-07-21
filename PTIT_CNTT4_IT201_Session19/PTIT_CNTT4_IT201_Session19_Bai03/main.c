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
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void) {
    int values[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap gia tri node %d:\n", i + 1);
        scanf("%d", &values[i]);
    }
    Node *root = createNode(values[0]);
    Node *one = createNode(values[1]);
    Node *two = createNode(values[2]);
    Node *three = createNode(values[3]);
    Node *four = createNode(values[4]);

    root->left=one;
    root->right=two;
    root->left->left=three;
    root->left->right=four;
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}