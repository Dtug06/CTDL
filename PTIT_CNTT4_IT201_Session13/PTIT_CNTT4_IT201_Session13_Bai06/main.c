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
int main(void) {
    char str[101];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("Chuoi vua nhap: %s\n", str);
     if (isPalindrome(str)) {
         printf("La chuoi doi xung");
     }else {
         printf("khong phai chuoi doi xung  ");
     }
    return 0;
}