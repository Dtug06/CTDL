#include <stdio.h>
int sum(const char arr[], int size);
int main(void) {
   char arr[50];
    int sumNum=0;
    printf("Nhap so");
    fgets(arr,50,stdin);
    int len = strlen(arr);
    if (arr[len - 1] == '\n') {
        arr[len - 1] = '\0';
        len--;
    }
    int total=sum(arr,len);
    printf("Tong la %d",total);
    return 0;
}
int sum(const char arr[], int size) {
    if (size == 0) return 0;
    return (arr[size - 1] - '0') + sum(arr, size - 1);
}