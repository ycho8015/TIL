#include <stdio.h>
int n;
long long int m;

long long int getExponents(long long int m) {
  if (m == 0)
    return 1;
  
  return n * getExponents(m - 1) % 10007;
}

int main() {
	scanf("%d %lld", &n, &m);
  
  while (m / 10007 != 0) 
    m = m / 10007 + m % 10007;
  
	long long int result = getExponents(m);
	printf("%lld", result);
	return 0;
}