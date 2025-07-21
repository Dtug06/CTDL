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
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
Node* searchDFS(Node* root, int target) {
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    Node* leftResult = searchDFS(root->left, target);
    if (leftResult != NULL) return leftResult;
    return searchDFS(root->right, target);
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
    printf("\n");
    inorder(root);

    printf("\n");
    int findData;
    printf("Nhap data can tim");
    scanf("%d", &findData);
    Node *findNode = searchDFS(root, findData);
    if (findNode!=NULL) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}