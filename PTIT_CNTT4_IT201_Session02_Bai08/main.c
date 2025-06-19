#include <stdio.h>
void check(int arr[],int size);
int main(void) {
    printf("nhap so luong phan tu N");
    int n=0;
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) {
        printf("nhap phan tu %d \n ", i+1);
        scanf("%d", &a[i]);
    }
    check(a,n);
    return 0;
}
void check(int arr[],int size) {
  for (int i = 0; i < size; i++) {
      int isGreater=1;
      for (int j = i+1; j < size; j++) {
          if (arr[i]<=arr[j]) {
           isGreater=0;
              break;
          }
      }
      if (isGreater) {
          printf("%d \t ", arr[i]);
      }
  }
}
