#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    int arr[n];
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nMang ban dau:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    printf("Mang sau khi sap xep:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n")
    int target;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);
    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1)
        printf("Tim thay bang Linear Search tai vi tri thu %d (index %d)\n", linearResult + 1, linearResult);
    else
        printf("Linear Search: Khong tim thay %d\n", target);
    int binaryResult = binarySearch(arr, n, target);
    if (binaryResult != -1)
        printf("Tim thay bang Binary Search tai vi tri thu %d (index %d)\n", binaryResult + 1, binaryResult);
    else
        printf("Binary Search: Khong tim thay %d\n", target);
    return 0;
}
