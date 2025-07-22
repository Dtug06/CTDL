#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNodeFromInput() {
    int value;
    printf("Nhập số nguyên cho node: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
int main() {
    Node* root = createNodeFromInput();
    if (root != NULL) {
        printf("Đã tạo node với dữ liệu: %d\n", root->data);
    }
    return 0;
}
