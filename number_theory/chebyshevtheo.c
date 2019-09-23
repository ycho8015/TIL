#include <stdio.h>
#include <stdbool.h>

const int MAX = 123456 * 2 + 1;

int main() {
  
  int primes[MAX]={0};
  
  for (int i = 2; i <= MAX; i++) {
    int multiplier = 2;
    while (multiplier * i < MAX) {
      primes[i * multiplier] = 1;
      multiplier++;
    }
  }
  
  
  while (true) {
    int n;
    scanf("%d", &n);
    
    if (n == 0) break;
    
    int num_primes = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
      if (primes[i] == 0) num_primes++;
    }
    printf("%d\n", num_primes);
  }
  return 0;
}