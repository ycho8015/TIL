#include <stdio.h>
#include <stdbool.h>
    
int main() {
  int n;
  scanf("%d", &n);
  
  int start = 0, end = 1, cnt = 1;
  while(true) {
    if (n > start && n <= end) {
      printf("%d", cnt);
      return 0;
    } else {
      start = end;
      end = end + 6 * cnt++;
    }
  }
  
  return 0;
}