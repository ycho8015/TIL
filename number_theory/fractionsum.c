#include <stdio.h>

int main() {
  int fractions[2][2];
  scanf("%d %d", &fractions[0][0], &fractions[0][1]);
  scanf("%d %d", &fractions[1][0], &fractions[1][1]);

  int numerator = fractions[0][0] * fractions[1][1] + fractions[1][0] * fractions[0][1];
  int denominator = fractions[0][1] * fractions[1][1];
  
  int gcd = numerator, b = denominator, r;
  
  while (b != 0) {
    r = gcd % b;
    gcd = b;
    b = r;
  }
  
  printf("%d %d", numerator / gcd, denominator / gcd);
  return 0;
}