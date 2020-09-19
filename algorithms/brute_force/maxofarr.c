#include <stdio.h>

int main() {

  int arr[9][9];
  int max_val = 0, y, x;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d ", &arr[i][j]);
      if (arr[i][j] > max_val) {
        max_val = arr[i][j];
        y = i;
        x = j;
      }
    }
  }
  
  printf("%d\n%d %d", max_val, y + 1, x + 1);
  return 0;
}