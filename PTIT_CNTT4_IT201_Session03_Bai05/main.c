#include <stdio.h>
#include <stdlib.h>

void diagonalMain(int** arr, int rows, int cols);
void minorDiagonal(int** arr, int rows, int cols);

int main(void) {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
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
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation error.\n");
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

    if (rows == cols) {
        diagonalMain(matrix, rows, cols);
        minorDiagonal(matrix, rows, cols);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void diagonalMain(int** arr, int rows, int cols) {
    int sumDiagonal = 0;
    for (int i = 0; i < rows; i++) {
        sumDiagonal += arr[i][i];
    }
    printf("Tong duong cheo chinh = %d\n", sumDiagonal);
}

void minorDiagonal(int** arr, int rows, int cols) {
    int sumDiagonal = 0;
    for (int i = 0; i < rows; i++) {
        sumDiagonal += arr[i][cols - 1 - i];
    }
    printf("Tong duong cheo phu = %d\n", sumDiagonal);
}
