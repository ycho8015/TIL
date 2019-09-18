#include <stdio.h>

int main() {
    
  int n;
  scanf("%d", &n);
  
  int arr[100];
  for (int i = 0; i < n; i++) {
    scanf("%d ", &arr[i]);
  }
  
  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      sum += ++cnt;
    } else {
      cnt = 0;
    }
  }
  
  printf("%d", sum);
  return 0;
}