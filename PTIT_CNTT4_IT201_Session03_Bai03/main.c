#include <stdio.h>
#include <stdlib.h>


int averageEvenNumber(int arr[], int size) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
            count++;
        }
    }
    if (count > 0) {
        return sum / count;
    } else {
        return -1;
    }
}

int main(void) {
    int n;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int average = averageEvenNumber(arr, n);
    if (average == -1) {
        printf("Khong co so chan trong mang\n");
    } else {
        printf("average = %d\n", average);
    }

    free(arr);
    return 0;
}
