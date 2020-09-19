#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[100][100];
  int cnt = 1;
  int i = 0, j = 0;
  
  while (cnt <= n * (n + 1) / 2) {
    arr[i][j] = cnt++;
    if (j == 0) {
      j = i + 1;
      i = 0;
    } else {
      i++;
      j--;
    }
  } 

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}