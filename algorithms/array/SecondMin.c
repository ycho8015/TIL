// return second min elem and its idx
#include <stdio.h>

int main() {
  int arr[10];
  int min_v, min_i, n_min_v = 99999999, n_min_i = 0;
  
  for (int i = 0; i < 9; i++) {
    scanf("%d", &arr[i]);
    if (i == 0) {
      min_v = arr[i];
      min_i = i;
    } else if (arr[i] < min_v) {
      n_min_v = min_v;
      n_min_i = min_i;
      min_v = arr[i];
      min_i = i;
    } else if (n_min_v > min_v && n_min_v > arr[i]) {
      n_min_v = arr[i];
      n_min_i = i;
    }
  }
  printf("%d\n%d", n_min_v, n_min_i + 1);
  return 0;
}