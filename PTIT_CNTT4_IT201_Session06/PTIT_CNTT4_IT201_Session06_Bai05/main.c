#include <stdio.h>

int findMax(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int maxRest = findMax(arr, n - 1);
    return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;
}
int findMin(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int minRest = findMin(arr, n - 1);
    return (arr[n - 1] < minRest) ? arr[n - 1] : minRest;
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Mang rong!\n");
        return 0;
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int min = findMin(arr, n);
    int max = findMax(arr, n);
    printf("Gia tri nho nhat: %d\n", min);
    printf("Gia tri lon nhat: %d\n", max);

    return 0;
}
