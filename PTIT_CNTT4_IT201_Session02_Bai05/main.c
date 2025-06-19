#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    int indexDelete = 0;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("Nhap vi tri muon xoa (bat dau tu 1): ");
    scanf("%d", &indexDelete);
    if (indexDelete < 1 || indexDelete > n) {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }
    for (int i = indexDelete - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    arr = (int*)realloc(arr, n * sizeof(int));
    printf("Mang sau khi xoa:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    free(arr);
    return 0;
}
