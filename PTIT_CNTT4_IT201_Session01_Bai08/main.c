#include <stdio.h>
void maxDoublNumber(int arr[]);
int main(void) {
    int arr[]={1,56,78,12,45,78,9,56,90,22,22,22};
    for (int i=0;i<12;i++) {
        printf(" %d",arr[i]);
    }
    maxDoublNumber(arr);
    return 0;
}
//Độ phức tạp của thuật toán là O(n^2)
void maxDoublNumber(int arr[]) {
    int max=0;
    int index=0;
    for (int i=0;i<12;i++) {
        int temp=0;
      for (int j=0;j<12;j++) {
          if (arr[j]==arr[i]) {
              temp++;
              if (temp>max) {
                 max=temp;
                  index=arr[i];
              }
          }
      }
    }
    printf(" \n Xuat hien nhieu nhat la so %d voi %d xuat hien ",index,max );
}