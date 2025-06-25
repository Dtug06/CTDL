#include <stdio.h>

int main(void) {
    int n, value;
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &value);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("%d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Không tìm thấy phần tử\n");
    }
    return 0;
}
