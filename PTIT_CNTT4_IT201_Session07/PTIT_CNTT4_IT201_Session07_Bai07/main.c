#include <stdio.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }
    int arr[n], negatives[n], positives[n];
    int countNeg = 0, countPos = 0, zeroCount = 0;
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            negatives[countNeg++] = arr[i];
        } else if (arr[i] > 0) {
            positives[countPos++] = arr[i];
        } else {
            zeroCount++;
        }
    }
    printf("\nMang truoc khi sap xep:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    int result[n];
    int index = 0;
    for (int i = 0; i < countNeg; i++) {
        result[index++] = negatives[i];
    }
    for (int i = 0; i < zeroCount; i++) {
        result[index++] = 0;
    }
    for (int i = 0; i < countPos; i++) {
        result[index++] = positives[i];
    }
    printf("\nMang sau khi sap xep:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("]\n");

    return 0;
}
