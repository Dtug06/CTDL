#include <stdio.h>

void countIndex(int arr[], int size);

int main(void) {
    int n;
    printf("Nhap so luong phan tu N");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    countIndex(a, n);
    return 0;
}

void countIndex(int arr[], int size) {
    int counted[size];
    for (int i = 0; i < size; i++) {
        counted[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (counted[i] == 1)
            continue;

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
        }
        printf("Phan tu %d xuat hien  %d lan \n", arr[i], count);
    }
}
