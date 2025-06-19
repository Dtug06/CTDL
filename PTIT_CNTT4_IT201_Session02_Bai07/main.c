#include <stdio.h>

int main(void) {
    int n ;
    int value=0;
    printf("Enter a number : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter value");
    scanf("%d", &value);
    for (int i=0;i<n;i++) {
        printf("Enter value index %d",i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0;i<n;i++) {
        printf("arr[%d]=%d \t",i+1,arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == value) {
                printf("%d + %d = %d\n", arr[i], arr[j], value);
                break;
            }
        }
    }



    return 0;
}