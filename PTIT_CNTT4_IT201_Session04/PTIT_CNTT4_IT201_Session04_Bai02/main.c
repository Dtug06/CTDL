#include <stdio.h>

int main(void) {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=arr[0];
    int index=0;
    for (int i=0;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
            index=i;
        }
    }
    printf("\n %d",index);
    return 0;
}