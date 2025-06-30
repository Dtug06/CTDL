#include <stdio.h>

void selectionSort(int arr[], int size, int start);
int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("So luong khong hop le.\n");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n, 0);
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}
void selectionSort(int arr[], int size, int start) {
    if (start >= size - 1) {
        return;
    }
    int minIndex = start;
    for (int i = start + 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }
    selectionSort(arr, size, start + 1);
}
