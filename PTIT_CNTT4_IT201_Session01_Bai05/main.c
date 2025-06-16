#include <stdio.h>
 void sortArr(int arr[],int size);
int main(void) {
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int size=sizeof(arr)/sizeof(int);
    for(int i=0;i<size;i++) {
        printf("%d\n",arr[i]);
    }
    sortArr(arr,size);
    for(int i=0;i<size;i++) {
        printf("%d\n",arr[i]);
    }
    return 0;
}
//độ phức tạp thuật toán O(n^2)
void sortArr(int arr[],int size){
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-1-i;j++) {
            if (arr[j]>arr[j+1]) {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}