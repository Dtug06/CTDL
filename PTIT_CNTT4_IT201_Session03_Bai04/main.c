#include <stdio.h>
#include <stdlib.h>


void findMaxValue(int** arr, int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("max = %d\n", max);
}


void findMinValue(int** arr, int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    printf("min = %d\n", min);
}

int main(void) {
    int rows, cols;
    printf("Nhap so hang (1 - 999): ");
    scanf("%d", &rows);
    printf("Nhap so cot (1 - 999): ");
    scanf("%d", &cols);

    // Validate rõ ràng
    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
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


    int** matrix = (int**)malloc(sizeof(int*) * rows);
    if (matrix == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * cols);
        if (matrix[i] == NULL) {
            printf("Khong the cap phat bo nho\n");
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
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


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }


    findMaxValue(matrix, rows, cols);
    findMinValue(matrix, rows, cols);


    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
