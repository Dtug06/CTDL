#include <stdio.h>
int printFibonacci(int n);
int main(void) {
    int n;
    printf("Nhap so luong phan tu ");
    scanf("%d", &n);
    if (n==0) {
        printf("Error!");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = printFibonacci(i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d \t ", arr[i]);
    }
    return 0;
}
int printFibonacci(int n) {
    if (n==0) {
        return 0;
    }else if (n==1) {
        return 1;
    }else {
       return printFibonacci(n-2)+printFibonacci(n-1);
    }

}