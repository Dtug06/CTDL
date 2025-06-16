#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void checkArr(int arr[]);
void checkArr1(int arr[]);
int main(void) {
    int arr[12];
    srand(time(NULL));

    for (int i = 0; i < 12; i++) {
        arr[i] = rand() % 100;
    }
    printf("Mang ngau nhien:\n");
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }
    printf("Lua chon kieu kiem tra, bam 1 or 2 \n");
    int choice;
    scanf("%d",&choice);
    if (choice==1) {
        checkArr(arr);
    }else {
        checkArr1(arr);
    }
    return 0;
}
//ham nay co do phuc tap la O(n^2)
void checkArr(int arr[]) {
    int flag=0;
    for (int i=0;i<12;i++) {
        int index=0;
        for (int j=0;j<12;j++) {
            if (arr[i]==arr[j]) {
                   index++;
                if (index>=2) {
                    flag=1;
                    break;
                }
            }
        }
        if (flag) break;
    }
    if (flag) {
        printf(" \n Mang arr co phan tu trung lap");
    }else {
        printf(" \n Mang arr khong phan tu trung lap");
    }
}
// độ phức tạp là O(n) nhưng bị giới giạn về bộ nhớ khi mảng quá lớn
void checkArr1(int arr[]) {
    int flag=0;
    int count[100]={0};//vì mảng 12 phần tử chỉ rand 1-99 nên có mảng phụ đếm
    for (int i=0;i<12;i++) {
        count[arr[i]]++;
        if (count[arr[i]]>=2) {
            printf(" \n Mang co phan tu trung lap ");
            flag=1;
            break;
        }
    }
    if (flag) {
        printf(" \n Mang co phan tu trung lap ");
    }else {
        printf(" \n Mang khong phan tu trung lap ");
    }
}