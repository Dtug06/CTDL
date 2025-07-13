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

int main(void) {
    queue q;
    initQueue(&q,5);
    inQueue(&q,1);
    inQueue(&q,2);
    inQueue(&q,3);
    inQueue(&q,4);
    inQueue(&q,5);
    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    } else {
        printQueue(&q);
    }
    return 0;
}