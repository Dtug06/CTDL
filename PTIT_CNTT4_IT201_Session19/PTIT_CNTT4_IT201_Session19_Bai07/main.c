#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
Node* searchDFS(Node* root, int target) {
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    Node* leftResult = searchDFS(root->left, target);
    if (leftResult != NULL) return leftResult;

    return searchDFS(root->right, target);
}
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}
Node* searchBFS(Node* root, int target) {
    if (root == NULL) return NULL;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == target) return current;

        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }

    return NULL;
}
void insertNode(Node* root, int value) {
    if (root == NULL) return;
    Queue* q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }
}
int main(void) {
    int values[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap gia tri node %d: ", i + 1);
        scanf("%d", &values[i]);
    }
    Node *root = createNode(values[0]);
    Node *one = createNode(values[1]);
    Node *two = createNode(values[2]);
    Node *three = createNode(values[3]);
    Node *four = createNode(values[4]);
    root->left = one;
    root->right = two;
    root->left->left = three;
    root->left->right = four;
    int newValue;
    printf("\nNhap gia tri can them vao cay: ");
    scanf("%d", &newValue);
    insertNode(root, newValue);
    printf("Cay sau khi them node : ");
    preorder(root);
    printf("\n");
    return 0;
}
