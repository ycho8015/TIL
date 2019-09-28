#include <stdio.h>

long long int getOrder(int n, long long int x) {
  long long int result = 0;
  
  for (long long int i = 1; i <= n; i++) {
    if (i * n < x) {
      result += n;
    } else {
      if (x % i == 0)
        result += x / i - 1;
      else
        result += x / i;
    }
  }
  return result + 1;
}

int main() {
  int n;
  long long int k;
  scanf("%d\n%lld", &n, &k);
  
  long long int start = 1;
  long long int end = n * n + 1;
  
  while (start + 1 < end) {
    long long int mid = start + (end - start) / 2;
    long long int order = getOrder(n, mid);
    
    if (order <= k) 
      start = mid;
    else 
      end = mid;
    
  }
  printf("%lld", start);
  
  return 0;
}