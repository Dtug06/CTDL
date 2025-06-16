#include <stdio.h>
void demNumber(int arr[],int size);
int main(void) {
  int arr[]={1,1,1,1,4,2,3,5,7,9,0,10,5,7,8,6,5,12,14,16,18,20,100};
    int size=sizeof(arr)/sizeof(arr[0]);
    demNumber(arr,size);
    return 0;
}
// độ phức tạp của thuật toán là O(n)
void demNumber(int arr[],int size) {
    int n;
    int index=0;
    printf("Nhập số lần xuất hiện của N ");
    scanf("%d",&n);
    for (int i=0;i<=size-1;i++) {
        if (n==arr[i]) {
            index++;
        }
    }
    printf("Số lần xuất hiện của N là %d ",index);
}