#include <stdio.h>

int main() {
  long long int A, B;
  scanf("%lld %lld", &A, &B);
  
  long long int a = A, b = B, r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  
  printf("%lld", A * B / a);
  return 0;
}