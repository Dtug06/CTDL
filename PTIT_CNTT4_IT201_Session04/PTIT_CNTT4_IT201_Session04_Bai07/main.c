#include <stdio.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d",i+1);
        scanf("%d", &arr[i]);
    }
    printf("Mang sau khi nhap \n");
    for (int i = 0; i < n; i++) {
        printf("%d \t",arr[i]);
    }
    int flag=0;
    //cac cap doi xung
    printf(" \n Cac cap doi xung \n");
    for (int i =0;i<n/2;i++) {
        if (arr[i]==arr[n-1-i]) {
            printf("%d\t",arr[i]);
            printf("%d\t",arr[n-1-i]);
            printf("\n");
            flag=1;
        }
    }
    if (!flag) {
        printf("Key khong ton tai trong mang");
    }

    return 0;
}