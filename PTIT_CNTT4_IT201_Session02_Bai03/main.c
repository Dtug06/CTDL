#include <stdio.h>
 void reverseArray(int *arr, int size);
int main(void) {
    printf("nhap so luong phan tu N");
    int n=0;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) {
        printf("nhap phan tu %d \n ", i+1);
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n;i++) {
        printf("%d \t  ", a[i]);
    }
    reverseArray(a, n);
    return 0;
}
 void reverseArray(int *arr, int size) {
    for(int i=0;i<(size-1)/2;i++) {
        int temp = arr[i];
        arr[i] = arr[size-2-i];
        arr[size-2-i] = temp;
    }
    for(int i=0;i<size-1;i++) {
        printf("%d \t  ", arr[i]);
    }
}