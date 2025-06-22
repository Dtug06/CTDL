#include <stdio.h>

int main(void) {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int position = 0;
    int value = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\nNhap vi tri muon sua (bat dau tu 0): ");
    scanf("%d", &position);
    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
    if (position >= 0 && position < n) {
        arr[position] = value;
    } else {
        printf("Vi tri khong hop le!\n");
        return 1; 
    }
    printf("Mang sau khi sua:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
