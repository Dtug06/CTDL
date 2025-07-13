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
    q->front=-1;
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
int main(void) {
    queue q;
    initQueue(&q,10);

    return 0;
}