#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int *data;
     int top;
     int max;
 }Stacks;
  Stacks creatStack(int max) {
      Stacks s;
      s.data = (int *)malloc(max * sizeof(int));
      s.top = -1;
      s.max = max;
      return s;
  }
int main(void) {

      Stacks s = creatStack(5);

    return 0;
}