#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  if (n % 4 == 0) 
    printf("NO");
  else 
    printf("YES");
  
  return 0;
}