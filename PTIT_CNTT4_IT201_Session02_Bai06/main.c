#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n = 100;
    int position=0;
    int value=0;
    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
    }
    printf("Mang ngau nhien \n");
    for (int i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("Enter position to add"); // gia su index muon them hop le =))
    scanf("%d", &position);
    n++;
    arr=(int*)realloc(arr, n * sizeof(int));
    for (int i=n-1;i>position-1;i--) {
        arr[i]=arr[i-1];
    }
    printf("Value to add\t \n");
    scanf("%d",&value);
    arr[position-1]=value;
    for (int i = 0; i < n; i++) {
        printf("%4d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    free(arr);
    return 0;
}