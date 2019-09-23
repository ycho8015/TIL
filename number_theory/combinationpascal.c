#include <stdio.h>
const int MAX = 31;
int pascal_triangle[MAX][MAX];


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i + 1) {
        pascal_triangle[i][j] = 1;
      } else {
        pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
      }
    }
  }
  
  printf("%d", pascal_triangle[n][m]);
  return 0;
}