#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int map[101][101]={0};
  
  for (int i = 1; i <= n; i++) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    
    for (int j = y1; j < y1 + y2; j++) {
      for (int k = x1; k < x1 + x2; k++) {
        map[j][k] = i;
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < 101; j++) {
      for (int k = 0; k < 101; k++) {
        if (map[j][k] == i)
          cnt++;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}