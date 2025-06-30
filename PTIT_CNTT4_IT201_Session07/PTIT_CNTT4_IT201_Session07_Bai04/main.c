#include <stdio.h>
#include <string.h>
#include <ctype.h>
void sortString(char str[]) {
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

int main(void) {
    char str[100];
    printf("Nhap chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    if (len == 0) {
        printf("Chuoi khong hop le.\n");
        return 1;
    }
    printf("\nChuoi truoc khi sap xep: \"%s\"\n", str);
    sortString(str);
    printf("Chuoi sau khi sap xep: \"%s\"\n", str);
    return 0;
}
