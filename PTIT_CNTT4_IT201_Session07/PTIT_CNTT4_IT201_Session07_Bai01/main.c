#include <stdio.h>
 void bubleSort(int arr[],int size);
int main(void) {
    int n;
    printf("Nhap so luong phan tu ");
    scanf("%d", &n);
    if (n<0||n>1000) {
        return 1;
    }
    int arr[n];
    for (int i=0;i<n;i++) {
        printf("Phan tu %d",i+1);
        scanf("%d",&arr[i]);
    }
    bubleSort(arr,n);
    for (int i=0;i<n;i++) {
        printf("%d  \t ",arr[i]);
    }
    return 0;
}
void bubleSort(int arr[],int size) {
    if (size==1) {
        return;
    }
    for (int i=0;i<size-1;i++) {
        if (arr[i]>arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubleSort(arr,size-1);
}