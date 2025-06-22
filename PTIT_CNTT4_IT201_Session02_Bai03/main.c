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
<<<<<<< HEAD
void reverseArray(int *arr, int size) {
=======
 void reverseArray(int *arr, int size) {
>>>>>>> 246aff6d666d588f5fa4fc44acc5010c0c8f552b
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    for (int i = 0; i < size; i++) {
        printf("%d \t", arr[i]);
    }
}
