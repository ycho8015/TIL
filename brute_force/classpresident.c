#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[1005][1005][2] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d ", &arr[i][j][0]);
    }
  }
  
  for (int k = 0; k < n; k++) {
    for (int j = 0; j < 5; j++) {
      for (int i = 0; i < n; i++) {
        if (i != k && arr[i][j][0] == arr[k][j][0]) {
          arr[k][i][1] = 1;
        }
      }
    }
  }

  int check[1005] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        check[i] += arr[i][j][1];
    }   
  }

  int max_num = 0, president_idx = 0;
  for (int i = 0; i < n; i++) {
    if (max_num < check[i]) {
      max_num = check[i];
      president_idx = i;
    }
  }
  
  printf("%d", president_idx + 1);
  return 0;
}