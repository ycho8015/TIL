#include <stdio.h>

int main() {

  int n, m;
  int arr[100][100];
  scanf("%d %d", &n, &m);
  
  int num;
  for (int i = 0; i < n; i++) {
    for (int j = 0;j < m; j++) {
      scanf("%d ", &num);
      arr[i][m - j - 1] = num;
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}