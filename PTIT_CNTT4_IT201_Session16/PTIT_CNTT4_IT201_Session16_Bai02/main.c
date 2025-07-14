#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Không thể cấp phát bộ nhớ cho queue.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Node *createNode() {
    int value;
    printf("Nhập giá trị phần tử: ");
    scanf("%d", &value);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không thể cấp phát bộ nhớ cho node.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void enqueue(Queue *q) {
    Node *newNode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void printQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Rong.\n");
        return;
    }
    printf("Cac phan tu la : ");
    Node *current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Queue *q = createQueue();
    enqueue(q);
    printQueue(q);
    Node *cur = q->front;
    while (cur != NULL) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(q);
    return 0;
}

