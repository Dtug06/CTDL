#include <stdio.h>
void printDouble(int n);
int main() {
    return 0;
}
// độ phức tạp của thời gian là  O(log n)
void printDouble(int n){
    int i=1;
    while (i<n) {
        printf("%d", i);
        i*=2;
    }
}