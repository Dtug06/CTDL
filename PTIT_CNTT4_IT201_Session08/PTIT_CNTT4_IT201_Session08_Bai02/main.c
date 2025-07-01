#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    // Trường hợp xấu nhất: O(log n)
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int arr[n];
    printf("Nhap %d phan tu theo thu tu tang dan:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int search;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);

    int result = binarySearch(arr, n, search);

    if (result != -1) {
        printf("Phan tu %d nam o vi tri thu %d (index %d)\n", search, result + 1, result);
    } else {
        printf("Khong ton tai phan tu %d trong mang\n", search);
    }

    return 0;
}
