#include <stdio.h>

const int MAX = 100001;

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n;
  scanf("%d", &n);
  
  int data[MAX] = {0};
  for (int i = 0; i < n; i++) 
    scanf("%d", &data[i]);
    
  int result[MAX] = {0};
  result[0] = data[0];
  result[1] = result[0] + data[1];
  result[2] = max(result[1], max(result[0] + data[2], data[1] + data[2]));
  
  
  for (int i = 3; i < n; i++) 
    result[i] = max(result[i - 1], max(data[i] + data[i - 1] + result[i - 3], result[i - 2] + data[i]));
  
  printf("%d ", result[n - 1]);
  
  return 0;
}