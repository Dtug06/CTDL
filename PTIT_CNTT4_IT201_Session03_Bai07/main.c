#include <stdio.h>
#include <stdlib.h>

int sumRow(int** arr, int k, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += arr[k][j];
    }
    return sum;
}

int main(void) {
    int rows, cols, k;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    // Kiểm tra hợp lệ cho rows và cols
    if (rows <= 0 && cols <= 0) {
        printf("So hang va so cot khong hop le\n");
        return 1;
    } else if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 1;
    } else if (cols <= 0) {
        printf("So cot khong hop le\n");
        return 1;
    } else if (rows >= 1000 || cols >= 1000) {
        printf("Gia tri khong hop le. Phai thoa man (0 < rows, cols < 1000)\n");
        return 1;
    }
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Khong the cap phat bo nho\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Nhap so hang can tinh tong (bat dau tu 0): ");
    scanf("%d", &k);

    if (k < 0 || k >= rows) {
        printf("Hang can tinh khong ton tai\n");
    } else {
        int sum = sumRow(matrix, k, cols);
        printf("sum = %d\n", sum);
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
