#include <stdio.h>
void checkMax(int arr[],int n);
int main(void) {
   printf("nhap so luong phan tu N");
    int n=0;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) {
        printf("nhap phan tu %d \n ", i+1);
        scanf("%d", &a[i]);
    }
    checkMax(a,n);
    return 0;
}
void checkMax(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        if(arr[i]>arr[i+1]) {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    printf("phan tu lon nhat trong mang la %d",arr[n-1]);
}