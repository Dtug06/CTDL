#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void) {
    int rows, cols;
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("Kich thuoc khong hop le.\n");
        return 1;
    }
    int matrix[rows][cols];
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int k;
    printf("Nhap so thu tu cot can sap xep (tu 0 den %d): ", cols - 1);
    scanf("%d", &k);
    if (k < 0 || k >= cols) {
        printf("So cot khong hop le.\n");
        return 1;
    }
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (matrix[i][k] > matrix[j][k]) {
                swap(&matrix[i][k], &matrix[j][k]);
            }
        }
    }
    printf("\n Ma tran sau khi sap xep cot %d:\n", k);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
