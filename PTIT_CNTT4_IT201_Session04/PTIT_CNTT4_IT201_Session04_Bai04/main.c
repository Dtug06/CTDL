#include <stdio.h>

int main(void) {
    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            index = i;
        }
    }
    if (index != -1) {
        printf("Chi so cuoi cung la: %d\n", index);
    } else {
        printf("Khong tim thay phan tu\n");
    }

    return 0;
}
