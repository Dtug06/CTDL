#include <stdio.h>

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int even[n], odd[n];
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even[evenCount++] = arr[i];
        else
            odd[oddCount++] = arr[i];
    }
    sortAscending(even, evenCount);
    sortDescending(odd, oddCount);
    int result[n];
    int index = 0;

    for (int i = 0; i < evenCount; i++)
        result[index++] = even[i];
    for (int i = 0; i < oddCount; i++)
        result[index++] = odd[i];

    printf("\nMang sau khi sap xep: [");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}
