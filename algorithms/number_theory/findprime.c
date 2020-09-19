#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  int num, num_primes = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    
    int flag = 0;
    if (num > 1) {
      for (int i = 2; i < num; i++) {
        if (num % i == 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        num_primes++;
      }
    }
  }

  printf("%d", num_primes);
  return 0;
}