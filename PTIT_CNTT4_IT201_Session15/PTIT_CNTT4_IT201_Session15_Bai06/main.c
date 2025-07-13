#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int size;
    int rear;
    int maxSize;
}queue;
void initQueue(queue *q,int maxSize){
    q->data=(int *)malloc(maxSize*sizeof(int));
    q->front=0;
    q->rear=-1;
    q->size=0;
    q->maxSize=maxSize;
}
int isEmpty(queue *q) {
    return q->size==0;
}
int isFull(queue *q) {
    return q->size==q->maxSize;
}
int inQueue(queue *q,int data) {
    if(isFull(q)) {
        printf("Queue is full\n");
        return 0;
    }
    else {
        q->rear++;
        q->data[q->rear]=data;
        q->size++;
        return 1;
    }

}
void printQueue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\n  ", q->data[i]);
        }
    }
}
int outQueue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    q->size--;

    return value;
}
int isIncreasingBy1(queue *q) {
    while (q->size > 1) {
        int a = outQueue(q);
        int b = q->data[q->front];
        if (b != a + 1)
            return 0;
    }
    return 1;
}
int main() {
    int n;
    scanf("%d", &n);
    queue q;
    initQueue(&q, n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        inQueue(&q, x);
    }
    if (isIncreasingBy1(&q))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
