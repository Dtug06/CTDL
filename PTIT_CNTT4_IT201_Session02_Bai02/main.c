#include <stdio.h>
void count(int arr[],int n);
int main(void) {
    printf("nhap so luong phan tu N");
    int n=0;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) {
        printf("nhap phan tu %d \n ", i+1);
        scanf("%d", &a[i]);
    }
    count(a,n);
    return 0;
}
void count(int arr[],int n) {
    int num;
    int index=0;
    printf("nhap N");
    scanf("%d",&num);
    for(int i=0;i<n;i++) {
        if(arr[i]==num) {
            index++;
        }
    }
    printf("so lan xuat hien %d la %d", num, index);
}