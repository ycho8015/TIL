#include <stdio.h>

int main() {

  int n;
  scanf("%d", &n);
  
  int num, cnt = 0;
  for (int i = 0; i < 5; i++) {
    scanf("%d ", &num);
    if (num == n) {
      cnt++;
    }
  }
  
  printf("%d", cnt);
  return 0;
}