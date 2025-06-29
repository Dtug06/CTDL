#include <stdio.h>
int sumNum(int n);
int main(void) {
    int sum=0;
    int n;
    printf("Nhap N");
    scanf("%d", &n);
    sum=sumNum(n);
    printf("%d",sum);
    return 0;
}
int sumNum(int n) {
    if (n==0) {
        return 0;
    }
    else {
        return n+sumNum(n-1);
    }
}