#include <stdio.h>

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  
  int arr[100][300];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2 * i + 1; j++) {
      if (s <= 9) {
        arr[i][j] = s++;
      } else {
        s = 1;
        arr[i][j] = s++;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = n - i - 1; j > 0; j--) {
      printf(" ");
    }
    
    if (i % 2 == 1) {
      for (int j = 0; j < 2 * i + 1; j++) {
        printf("%d", arr[i][j]);
      }
    } else {
      for (int j = 2 * i; j >= 0; j--) {
        printf("%d", arr[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}