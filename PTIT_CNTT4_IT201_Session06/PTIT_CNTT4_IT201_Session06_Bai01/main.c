#include <stdio.h>
  void TenToTwo(int n);
int main(void) {
    int n;
    printf("Nhap so can chuyen doi tu he hai sang 10");
    scanf("%d", &n);
    TenToTwo(n);
    return 0;
}
void TenToTwo(int n) {
    if (n == 0) return;
    TenToTwo(n / 2);
    printf("%d", n % 2);
}