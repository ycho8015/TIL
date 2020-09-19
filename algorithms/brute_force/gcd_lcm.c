#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int gcd, lcm;
  
  int A = a, B = b, r;
  while(B != 0) {
    r = A % B;
    A = B;
    B = r;
    
  }
  
  lcm = a * b / A;
  printf("%d\n%d", A, lcm);
  return 0;
}