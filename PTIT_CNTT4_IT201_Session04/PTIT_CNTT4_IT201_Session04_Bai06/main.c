#include <stdio.h>
#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    int age;
};

int main(void) {
    struct Student students[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Ten: ");
        scanf(" %[^\n]", students[i].name);  // đọc cả dòng (tên có khoảng trắng)

        printf("Tuoi: ");
        scanf("%d", &students[i].age);

        printf("\n");
    }
    int searchId;
    printf("Nhap ID can tim: ");
    scanf("%d", &searchId);
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchId) {
            printf("\n{ id: %d, name: \"%s\", age: %d }\n",
                   students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nSinh vien khong ton tai\n");
    }

    return 0;
}
