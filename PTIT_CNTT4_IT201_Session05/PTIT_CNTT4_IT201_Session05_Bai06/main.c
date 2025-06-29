#include <stdio.h>
int sumArr(int arr[],int n);
int main(void) {
   int n;
    int sum;
    printf("Nhap so luong phan tu N ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    sum=sumArr(arr,n);
    printf("Tong cua mang la %d",sum);
    return 0;
}
int sumArr(int arr[], int n) {
    if (n==0) {
        return arr[0];
    }else {
        return arr[n] + sumArr(arr, n-1);
    }

}