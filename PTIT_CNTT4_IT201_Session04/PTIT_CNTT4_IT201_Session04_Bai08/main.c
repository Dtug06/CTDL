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
    int key;
    int flag=0;
    printf("Nhap key");
    scanf("%d", &key);
    for (int i=0;i<n;i++) {
        if (arr[i]==key) {
            printf("%d \t",i);
            flag=1;
        }
    }
    if (!flag) {
      printf("Khong ton tai trong mang");
    }
    return 0;
}