#include <stdio.h>
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp=arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main(void) {
    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    sortArray(arr, n);
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    if (binarySearch(arr, 0, n - 1, value)) {
        printf("Phan tu co trong mang\n");
    } else {
        printf("Phan tu khong co trong mang\n");
    }
    return 0;
}
