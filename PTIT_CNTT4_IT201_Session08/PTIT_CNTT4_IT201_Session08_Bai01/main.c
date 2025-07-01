#include <stdio.h>
   int linearSearch(int a[], int n, int key);
int main(void) {
    int n;
    do {
        printf("Please enter a number: ");
        scanf("%d", &n);

    }while (n<=0||n>=1000);
    int arr[n];
    printf("Nhap cac phan tu trong mang \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key ;
    printf("Nhap gia tri can tim ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
    if (result!=-1) {
        printf("vi tri thu %d \n",result+1);
    }else {
        printf("khong ton tai trong mang");
    }
    /*
    Trường hợp tệ nhất (key nằm cuối hoặc không có): O(n)
    */

    return 0;
}
 int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}