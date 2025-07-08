#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int max;
}Stacks;
void init(Stacks *s, int index) {
    s->data = (int *)malloc(index * sizeof(int));
    s->top = -1;
    s->max = index;
}
Stacks creatStack(int max) {
    Stacks s;
    s.data = (int *)malloc(max * sizeof(int));
    s.top = -1;
    s.max = max;
    return s;
}
int isFull(Stacks *s) {
    return s->top == s->max - 1;
}
int isEmpty(Stacks *s) {
    return s->top == -1;
}
void push(Stacks *s,int data) {
    if(isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = data;
}
int pop(Stacks *s) {
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}
void reverseArray(int arr[],int n) {
     Stacks s;
     init(&s,100);
     for(int i=0;i<n;i++) {
         push(&s,arr[i]);
     }
     for (int i=0;i<n;i++) {
         arr[i]=pop(&s);
     }
 }
int main(void) {
     int arr[]={1,2,3,4,5,6,7,8,9};
     int n=sizeof(arr)/sizeof(arr[0]);
     printf("Mang ban dau \n");
     for (int i=0;i<n;i++) {
         printf("%d \n",arr[i]);
     }
     printf("\n Ham sau khi dao nguoc\n");
     reverseArray(arr,n);
     for (int i=0;i<n;i++) {
         printf("%d \n",arr[i]);
     }
    return 0;
}