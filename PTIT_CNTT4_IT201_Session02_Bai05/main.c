#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n=0;
    int indexDelete=0;
    printf("Nhap so luong phan tu ");
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        printf("%d \t",arr[i]);
    }
    printf("Enter index to delete");
    scanf("%d",&indexDelete);
    arr[indexDelete-1]=0;
    for (int i=indexDelete-1;i<n;i++) {
        arr[i]=arr[i+1];
    }
    n--;
    arr=(int*)realloc(arr,n*sizeof(int));
    for(int i=0;i<n;i++) {
        printf("%d \t",arr[i]);
    }
    free(arr);
    return 0;
}
