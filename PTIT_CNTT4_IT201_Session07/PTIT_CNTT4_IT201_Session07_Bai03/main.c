#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void) {
    int n;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nMang truoc khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    insertionSort(arr, n);
    printf("\n\nMang sau khi sap xep (chen tang dan):\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
