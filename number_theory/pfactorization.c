#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 2; n > 1; ) {
    if (n % i == 0) {
      n /= i;
      printf("%d\n", i);
    } else {
      i++;
    }
  }

  return 0;
}   