#include <stdio.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu ");
    scanf("%d", &n);
    int position=0;
    int value=0;
    int arr[n];
    for (int i=0;i<n;i++) {
        printf("Phan tu thu %d \t \n",i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0;i<n;i++) {
        printf(" %d \t \n",arr[i]);
    }
    printf("Nhap vi tri muon sua \t");
    scanf(" %d",&position);
    printf("Nhap gia tri muon sua \t ");
    scanf(" %d",&value);
    arr[position-1]=value;
    for (int i=0;i<n;i++) {
        printf(" %d \t \n",arr[i]);
    }
    return 0;
}