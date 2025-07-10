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
int first(stack *s, int *value) {
    if (isEmpty(s)) {
        printf("Mang rong mat ruiii!\n");
        return 0; // nếu trong trường hợp phần tử đầu tiên là -1 sẽ gây ra lỗi nên sẽ trả về  o
    }
    *value = s->top->data;
    return 1;
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
    int value;
    if (first(&s, &value)) {
        printf("Phan tu dau tien: %d\n", value);
    }
    return 0;
}