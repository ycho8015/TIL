#include <stdio.h>

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d ", &arr[i]);
  }
  
  for (int i = 0; i < n; i++) {
    int idx = i;
    for (int j = i; j < n; j++) {
      if (arr[idx] < arr[j]) {
        idx = j;
      }
    }
    int temp;
    temp = arr[i];
    arr[i] = arr[idx];
    arr[idx] = temp;
    if (i + 1 == k) {
      printf("%d", arr[i]);
      return 0;
    }
  }

  return 0;
}