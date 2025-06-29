#include <stdio.h>
void hanoi(int n, char from, char to, char via) {
    if (n <= 0) {
        printf("Input khong hop le\n");
        return;
    }
    if (n == 1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", from, to);
    } else {
        hanoi(n - 1, from, via, to);
        printf("Dia %d di chuyen tu %c sang %c\n", n, from, to);
        hanoi(n - 1, via, to, from);
    }
}
int main() {
    int n;
    printf("Nhap so dia: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        hanoi(n, 'A', 'C', 'B');
    }

    return 0;
}
