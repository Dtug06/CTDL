
#include <stdio.h>
#include <string.h>
int convertRecursiveHelper(const char *str, int index, int result) {
    if (str[index] == '\0') {
        return result;
    }
    if (str[index] < '0' || str[index] > '9') {
        return -1;
    }
    result = result * 10 + (str[index] - '0');
    return convertRecursiveHelper(str, index + 1, result);
}
int strToNum(const char *str) {
    return convertRecursiveHelper(str, 0, 0);
}

int main(void) {
    char arr[50];
    printf("Please enter a string: ");
    fgets(arr, 50, stdin);
    arr[strcspn(arr, "\n")] = '\0';
    printf("Chuoi da nhap: %s\n", arr);
    int result = strToNum(arr);
    if (result == -1) {
        printf("Chuoi khong hop le .\n");
    } else {
        printf("Chuoi sau khi chuyen: %d\n", result);
    }

    return 0;
}
