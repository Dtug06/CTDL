#include <stdio.h>
 int binarySreach(int arr[],int left,int right,int key);
int main(void) {
   int key;
  int n;
    printf("Nhap so luong phan tu");
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++) {
            printf("Nhap phan tu thu %d",i+1);
            scanf("%d",&arr[i]);
        }
        for (int i=0;i<n-1;i++) {
            for (int j=0;j<n-i-1;j++) {
                if (arr[j]>arr[j+1]) {
                    int temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        printf("Mang sau khi duoc sap xep\n");
        for (int i=0;i<n;i++) {
            printf("%d \t",arr[i]);
        }
    printf("Nhap key ");
    scanf("%d",&key);
    int resuit=binarySreach(arr,0,n-1,key);
    if (resuit) {
        printf("Tim thay phan tu o %d",resuit);
    }else {
        printf("Khong tim thay phan tu");
    }
        return 0;
}
binarySreach(int arr[],int left,int right,int key) {
    if (left>right) {
        return -1;
    }
    int mid = (left+right)/2;
    if (arr[mid]==key) {
        return mid;
    }
    if (arr[mid]<key) {
        return binarySreach(arr,left,mid-1,key);
    }
    if ( arr[mid]>key) {
        return binarySreach(arr,mid+1,right,key);
    }
}