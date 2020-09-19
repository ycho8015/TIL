#include <stdio.h>
#include <stdbool.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int base[2][2] = {0};
  
  for (int i = n - m + 1; i <= n; i++) {
    if (i % 2 == 0 || i % 5 == 0) {
      int r = i;
      while (true) {
        if (r % 2 == 0) {
          base[0][0] += 1;
          r /= 2;
        }
        
        if (r % 5 == 0) {
          base[0][1] += 1;
          r /= 5;
        }
        
        if (r % 2 != 0 && r % 5 != 0) break;
      }
    }
  }
  
  for (int i = 1; i <= m; i++) {
    if (i % 2 == 0 || i % 5 == 0) {
      int r = i;
      while (true) {
        if (r % 2 == 0) {
          base[1][0] += 1;
          r /= 2;
        }
        
        if (r % 5 == 0) {
          base[1][1] += 1;
          r /= 5;
        }
        
        if (r % 2 != 0 && r % 5 != 0) break;
      }
    }
  }
  
  base[0][0] -= base[1][0];
  base[0][1] -= base[1][1];
  
  if (base[0][0] > 0 && base[0][1] > 0) {
    printf("%d", base[0][1]);
  } else {
    printf("0");
  }
  return 0;
}