// return max elem and its idx
#include <stdio.h>

int main() {
  int arr[10];
  int max_val = 0, max_idx = 0;
  for (int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] > max_val) {
      max_val = arr[i];
      max_idx = i;
    }
  }
  printf("%d\n%d", max_val, max_idx+1);
  return 0;
}