#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct student {
    int id;
    char name[50];
    int age;
};

int main(void) {
    int n;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    getchar();

    struct student a[n];

    for (int i = 0; i < n; i++) {
        printf("\nNhap id hoc sinh thu %d: ", i + 1);
        scanf("%d", &a[i].id);
        getchar();
        printf("Nhap name hoc sinh thu %d: ", i + 1);
        fgets(a[i].name, sizeof(a[i].name), stdin);

        int len = strlen(a[i].name);
        if (a[i].name[len - 1] == '\n') {
            a[i].name[len - 1] = '\0';
        }

        for (int j = 0; j < strlen(a[i].name); j++) {
            a[i].name[j] = toupper(a[i].name[j]);
        }

        printf("Nhap tuoi hoc sinh thu %d: ", i + 1);
        scanf("%d", &a[i].age);
        getchar();
    }

    char findName[50];
    printf("\nNhap ten can tim: ");
    fgets(findName, sizeof(findName), stdin);

    int length = strlen(findName);
    if (findName[length - 1] == '\n') {
        findName[length - 1] = '\0';
        length--;
    }


    for (int i = 0; i < length; i++) {
        findName[i] = toupper(findName[i]);
    }

    printf("\nKet qua tim kiem:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(a[i].name, findName)) {
            printf("ID: %d, Ten: %s, Tuoi: %d\n", a[i].id, a[i].name, a[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay hoc sinh co ten \"%s\"\n", findName);
    }

    return 0;
}
