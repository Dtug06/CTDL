#include <stdio.h>
 int fibonancci(int i);
int main(void) {
    int n;
    printf("Nhap so luong phan tu ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i]=fibonancci(i);
    }
    //day fibonancci dao nguoc
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
int fibonancci(int i) {
    if (i == 0) {
        return 0;
    }else if (i==1) {
        return 1;
    }
    return fibonancci(i-1) + fibonancci(i-2);
}