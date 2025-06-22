#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;

    printf("Nhap so luong phan tu ban dau (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &m);

    if (m < 0) {
        printf("So luong them khong hop le\n");
        free(arr);
        return 1;
    }
    arr = (int*)realloc(arr, (n + m) * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat lai bo nho\n");
        return 1;
    }
    for (int i = 0; i < m; i++) {
        printf("Phan tu moi %d: ", i + 1);
        scanf("%d", &arr[n + i]);
    }
    printf("Mang sau khi them:\n[ ");
    for (int i = 0; i < n + m; i++) {
        printf("%d", arr[i]);
        if (i < n + m - 1) printf(", ");
    }
    printf(" ]\n");
    free(arr);
    return 0;
}
