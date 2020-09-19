#include <stdio.h>
#define MAX 1001

int map[MAX][MAX]={0};
int row, col, num;

int main() {
  scanf("%d %d", &row, &col);
  scanf("%d", &num);
  
  if (num > row * col) {
    printf("0");
    return 0;
  }
  
  int layer = 0;
  int cnt = 0;
  while (1) {
    for (int j = layer; j < col - layer; j++) {
      if (map[layer][j] == 0)
        map[layer][j] = ++cnt;
        if (cnt == num) {
          printf("%d %d", layer + 1, j + 1);
          return 0;
        }
    }
    
    for (int i = layer; i < row - layer; i++) {
      if (map[i][col - layer - 1] == 0)
        map[i][col - layer - 1] = ++cnt;
        if (cnt == num) {
          printf("%d %d", i + 1, col - layer);
          return 0;
        }
    }
    
    for (int j = col - layer - 1; j >= layer; j--) {
      if (map[row - layer - 1][j] == 0)
        map[row - layer - 1][j] = ++cnt;
        if (cnt == num) {
          printf("%d %d", row - layer, j + 1);
          return 0;
        }
    }
    
    for (int i = row - layer - 1; i >= layer; i--) {
      if (map[i][layer] == 0) {
        map[i][layer] = ++cnt;
        if (cnt == num) {
          printf("%d %d", i + 1, layer + 1);
          return 0;
        }
      } 
    }
    layer++;
  }
  return 0;
}