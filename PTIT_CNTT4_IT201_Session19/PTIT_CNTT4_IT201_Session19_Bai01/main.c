#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct queueNode {
    Node* treeNode;
    struct queueNode* next;
}QueueNode;
typedef struct {
    QueueNode* front;
    QueueNode* rear;
}Queue;
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
};
 int isEmpty(Queue* queue) {
     return queue->front==NULL;
 };
void enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newNode=(QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (queue->rear==NULL) {
        queue->front=queue->rear=newNode;
    }else {
        queue->rear->next=newNode;
        queue->rear=newNode;
    }
}
Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    if (temp->next==NULL) {
        queue->rear=queue->front=NULL;
        free(temp);
        return NULL;
    }
    queue->front=queue->front->next;
    return temp->treeNode;
}
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