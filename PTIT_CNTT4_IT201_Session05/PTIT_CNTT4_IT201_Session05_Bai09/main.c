#include <stdio.h>
int countPaths(int row, int col) {
    if (row == 1 || col == 1)
        return 1;
    return countPaths(row - 1, col) + countPaths(row, col - 1);
}

int main() {
    int row, col;
    printf("Nhap so hang, so cot (vd: 2 3): ");
    scanf("%d %d", &row, &col);

    int result = countPaths(row, col);
    printf("So duong di: %d\n", result);
    return 0;
}
