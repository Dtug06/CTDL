#include <stdio.h>
void inSo( int n);
int main(void) {
   int n;
    printf("nhap n");
    scanf("%d", &n);
    inSo(n);
    return 0;
}
void inSo(int n) {
    if (n==0) {
        return;
    }
    inSo(n-1);
    printf("%d \t",n);
}