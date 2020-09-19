#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d ", &arr[i]);
  }
  
  for (int i = 0; i < n; i++) {
    int idx = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[idx])
        idx = j;
    }
    int temp = arr[i];
    arr[i] = arr[idx];
    arr[idx] = temp;
  }
  
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}