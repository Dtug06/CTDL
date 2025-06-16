#include <stdio.h>
 int* mallocArray(int n);
int main(void) {
    return 0;
}
// độ phức tạp của bộ nhớ là O(n)
int* mallocArray(int n) {
    int* arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        arr[i]=i;
    }
    return arr;
}