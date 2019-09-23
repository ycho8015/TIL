#include <stdio.h>

int fibonacci(int x) {
  if (x <= 2) {
    if (x == 0) {
      return 0;
    } else {
      return 1;
    }
  }
  
  int seq[50];
  seq[0] = 0;
  seq[1] = 1;
  seq[2] = 1;
  
  for (int i = 3; i <= x; i++) {
    seq[i] = seq[i - 1] + seq[i - 2];
  }
    
  return seq[x];
}

int main() {
  int n;
  scanf("%d", &n);
  int sum = fibonacci(n);
  
  printf("%d", sum);
  return 0;
}