#include <stdio.h>

int main() {
  long long int n;
  scanf("%lld", &n);
  
  long long start = 0;
  long long int end = 1000000000;
  
  while (start + 1 < end) {
    long long mid = start + (end - start) / 2;
    if (mid * mid + mid > n) {
      end = mid;
    } else {
      start = mid;
    }
  }
  
  printf("%lld", start);
  return 0;
}