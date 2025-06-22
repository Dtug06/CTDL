#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Loi: So luong phan tu khong duoc am.\n");
        return 0;
    }
    if (n == 0) {
        printf("Loi: So luong phan tu phai lon hon 0.\n");
        return 0;
    }
    if (n >= 1000) {
        printf("Loi: So luong phan tu phai nho hon 1000.\n");
        return 0;
    }

    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Loi: Khong the cap phat bo nho!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d\n", i + 1, arr[i]);
    }

    free(arr);
    return 0;
}
