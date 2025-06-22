#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n = 100;
    int position = 0;
    int value = 0;
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    printf("Mang ngau nhien:\n");
    for (int i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\nNhap vi tri muon chen (bat dau tu 0, toi da %d): ", n);
    scanf("%d", &position);
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &value);
    if (position < 0 || position > n) {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }
    n++;
    arr = (int*)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Realloc that bai!\n");
        return 1;
    }
    for (int i = n - 1; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    printf("Mang sau khi chen:\n");
    for (int i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    free(arr);
    return 0;
}
