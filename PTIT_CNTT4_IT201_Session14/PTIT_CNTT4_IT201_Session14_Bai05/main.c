#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* top;
}stack;
void initStack(stack* s) {
    s->top = NULL;
}
int isEmpty(stack* s) {
    return s->top == NULL;
}
void push(stack *s,int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}
int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Rong");
        return -1;
    }
    Node* temp = s->top;
    int value=temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}
void printStack(stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep trong ");
    }
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int  first(stack *s) {
    if (isEmpty(s)) {
        printf("Mang rong mat ruiii!");
        return -1;
    }
    return s->top->data;
}
int main(void) {
    stack s;
    initStack(&s);
    int index;
    printf("Nhap so luong phan tu");
    scanf("%d",&index);
    for (int i = 0; i < index; i++) {
        int value;
        printf("Nhap value can them ");
        scanf("%d",&value);
        push(&s,value);
    }
    printStack(&s);
    printf("Phan tu dau tien \n");
    int data=first(&s);
    if (data!=-1) {
        printf("%d",data);
    }
    return 0;
}