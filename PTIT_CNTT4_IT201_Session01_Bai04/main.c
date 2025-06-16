#include <stdio.h>
int sumNumber(int n);
int main(void) {
    int n;
    int sum=0;
    printf("nhap day so can tinh tong");
    scanf("%d",&n);
    sum=sumNumber(n);
    printf("%d",sum);
    return 0;
}
int sumNumber(int n) {
    int sum=0;
    if (n<=0) {
        printf("N không hợp lệ ");
        return -1 ;
    }
    sum=(n*(n+1))/2;
    return sum;
}