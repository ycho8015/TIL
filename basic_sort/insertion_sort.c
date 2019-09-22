#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  
  for (int i = 0; i < n; i++) {
    scanf("%d ", &arr[i]);
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 1; j--) {
      if (arr[j - 1] > arr[j]) {
        int temp;
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      } else {
        break;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}