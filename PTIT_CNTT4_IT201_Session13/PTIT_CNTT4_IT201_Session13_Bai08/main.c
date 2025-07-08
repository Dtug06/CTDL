#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int isPalindrome(char str[]) {
    Stacks s;
    init(&s,100);
    int len=strlen(str);
    for(int i=0;i<len;i++) {
        push(&s,str[i]);
    }
    for (int i=0;i<len;i++) {
        if (str[i]!=pop(&s)) {
            return 0;
        }
    }
    return 1;
}
int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||(open == '[' && close == ']') ||(open == '{' && close == '}');
}
int checkValid(char str[]) {
    Stacks s;
    init(&s,strlen(str));
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s)) {
                return 0;
            }
            char open = pop(&s);
            if (!isMatching(open, c)) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}
int evaluatePostfix(char expr[]) {
    Stacks s;
    init(&s, 100);
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            push(&s, c - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Lỗi: chia cho 0!\n");
                        return 0;
                    }
                    result = a / b;
                    break;
                default:
                    printf("Toán tử không hợp lệ: %c\n", c);
                    return 0;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}


int main(void) {
    char expr[101];
    printf("Nhap bieu thuc hau to (postfix): ");
    fgets(expr, sizeof(expr), stdin);
    int len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') {
        expr[len - 1] = '\0';
    }
    int result = evaluatePostfix(expr);
    printf("Gia tri cua bieu thuc: %d\n", result);
    return 0;
}
