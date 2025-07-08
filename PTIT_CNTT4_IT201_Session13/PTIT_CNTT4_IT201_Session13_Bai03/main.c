#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int max;
}Stacks;
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
int main(void) {

    Stacks s = creatStack(5);
    int data;
    printf("Tien hanh them cac phan tu vao stack \n");
    for (int i=0;i<s.max;i++) {
        printf("Them phan tu ");
        scanf("%d",&data);
        push(&s,data);
    }

    int lastStack=pop(&s);
    printf("\n %d \n ",lastStack);

    return 0;
}