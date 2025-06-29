#include <stdio.h>
 int factorial(int n);
int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int Factorial=factorial(n);
    printf("Factorial %d", Factorial);
    return 0;
}
int factorial(int n) {
    if (n == 0) {
        return 1;
    }else {
        return n*factorial(n-1);
    }
}