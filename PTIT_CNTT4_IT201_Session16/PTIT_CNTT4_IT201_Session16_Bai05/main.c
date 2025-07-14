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
        printf("khong the cap phat cho queue.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Node *createNode() {
    int value;
    printf("NHap gia tri: ");
    scanf("%d", &value);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("khong the cap phat cho node.\n");
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
int isEmpty(Queue *q) {
    if (q->front == NULL) {
        printf("Rong.\n");
        return 1;
    }
    return 0;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
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
void peek(Queue *q) {
    if (q->front == NULL) {
        printf("Rong\n");
    } else {
        printf("Phan tu dau tien la : %d\n", q->front->data);
    }
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Khong the lay, hang doi rong.\n");
        return -1;
    }
    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}
int main() {
    Queue *q = createQueue();

    enqueue(q);
    enqueue(q);
    printQueue(q);
    int removed = dequeue(q);
    printf("Da lay ra: %d\n", removed);
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


