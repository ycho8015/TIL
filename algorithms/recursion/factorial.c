#include <stdio.h>

int getFactorial(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * getFactorial(n - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  int result = getFactorial(n);
  printf("%d", result);
  
  return 0;
}