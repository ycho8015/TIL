#include <stdio.h>
const int MAX = 101;
int main() {
  int n;
  scanf("%d", &n);
  
  int data[MAX] = {0};
  data[0] = 0;
  data[1] = 1;
  data[2] = data[1] + 1;
  
  for (int i = 3; i <= n; i++) {
    data[i] = data[i - 1] + data[i - 2];
    data[i] %= 1000007;
  }
  
  printf("%d", data[n]);
  return 0;
}