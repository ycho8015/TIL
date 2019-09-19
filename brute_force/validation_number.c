#include <stdio.h>

int main() {
  
  int num, ans = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%d ", &num);
    ans += num * num;
  }
  
  printf("%d", ans % 10);
  return 0;
}