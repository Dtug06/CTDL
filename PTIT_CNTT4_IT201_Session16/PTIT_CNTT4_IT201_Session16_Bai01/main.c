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
        printf("khong cap phat dc cho queue.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
