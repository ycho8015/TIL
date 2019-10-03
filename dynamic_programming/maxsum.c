#include <stdio.h>

const int MAX = 1000000;
int data[MAX];
int result[MAX];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &data[i]);
    
  result[0] = data[0];
  int max_sum = data[0];
  for (int i = 1; i < n; i++) {
    result[i] = max(data[i], data[i] + result[i - 1]);
    if (result[i] > max_sum)
      max_sum = result[i];
  }
  
  printf("%d", max_sum);
  return 0;
}