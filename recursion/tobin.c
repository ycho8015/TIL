#include <stdio.h>
int n, k;
int result[30];

void tobin(int x, int y) {
  if (y >= n) {
    if (x == k) {
      for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
      }
      printf("\n");
    }
  } else {
    if (x < k) {
      result[y] = 1;
      tobin(x + 1, y + 1);
    }
    result[y] = 0;
    tobin(x, y + 1);
  }
}
int main() {
  scanf("%d %d", &n, &k);
  
  tobin(0, 0);
  
  return 0;
}