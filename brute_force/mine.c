#include <stdio.h>

int main() {
  int n, m, x, y;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &y, &x);
  x -= 1, y -= 1;
  
  int map[105][105] = {0};
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d ", &map[i][j]);
      if ((i == y && j == x) && map[i][j] == 1) {
        printf("game over");
        return 0;
      }
    }
  }
  
  int sum = 0;
  for (int i = y - 1; i <= y + 1; i++) {
    for (int j = x - 1; j <= x + 1; j++) {
      if (map[i][j] == 1) {
        sum++;
      }
    }
  }
  
  printf("%d", sum);
  return 0;
}