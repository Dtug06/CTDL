#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max_count = 0;
    int max_element = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    printf("\nPhan tu xuat hien nhieu nhat: %d\n", max_element);
    printf("So lan xuat hien: %d\n", max_count);

    free(arr);
    return 0;
}
