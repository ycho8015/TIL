#include <stdio.h>
const int kMAX = 1000;
int data[kMAX][kMAX];
int result[kMAX][kMAX];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &data[i][j]);
      
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0)
        result[i][j] = data[i][j];
      else if (i == 0)
        result[i][j] = result[i][j - 1] + data[i][j];
      else if (j == 0)
        result[i][j] = result[i - 1][j] + data[i][j];
      else {
        result[i][j] = max(result[i - 1][j], result[i][j - 1]) + data[i][j];
      }
    }
  }
  
  printf("%d", result[n - 1][m - 1]);
  return 0;
}