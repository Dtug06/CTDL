#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//O(n^2)
void generateMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

//O(n^2)
void printMatrix(int n, int matrix[n][n]) {
    printf("Ma tran %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// O(n)
void printMainDiagonal(int n, int matrix[n][n]) {
    printf("Duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", matrix[i][i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap kich thuoc ma tran vuong n x n: ");
    scanf("%d", &n);

    int matrix[n][n];
    srand(time(NULL));

    generateMatrix(n, matrix);
    printMatrix(n, matrix);
    printMainDiagonal(n, matrix);

    return 0;
}
