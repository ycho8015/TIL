/*
input: 0 <= n <= 100

output:
*
**
***
...
*/

#include <stdio.h>

int main() {

  int n;
  scanf("%d", &n);
  int idx = 1;
  while(n != 0) {
    for (int i = 0; i < idx; i++) {
      printf("*");  
    }
    printf("\n");
    idx++;
    n--;
  }
  return 0;
}