#include <stdio.h>
 int sumTo(int firstNum,int secNum);
int main(void) {
  int firstNum,secNum;
    int sum;
    printf("Enter first number: ");
    scanf("%d",&firstNum);
    printf("Enter second number: ");
    scanf("%d",&secNum);
    if (firstNum<0||secNum<0||firstNum>secNum) {
        printf("Invalid Input");
        return 1;
    }
  sum=sumTo(firstNum,secNum);
    printf("The sum is %d",sum);
    return 0;
}
int sumTo(int firstNum,int secNum) {
    if (firstNum==secNum) {
        return firstNum;
    }
    else {
        return firstNum+sumTo(firstNum+1,secNum);
    }
}