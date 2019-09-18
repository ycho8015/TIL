#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[100][100];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", arr[a][b]);
  return 0;
}