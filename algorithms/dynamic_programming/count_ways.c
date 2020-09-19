#include <stdio.h>
const int MAX = 100005;
int data[MAX];

int main() {
  int n;
  scanf("%d", &n);
  
  int m = 3;
  
  data[0] = 0;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    sum += data[i - 1];
    data[i] = sum + 1;
  }
  
  for (int i = m + 1; i <= n; i++) {
    for (int j = i - m; j <= i - 1; j++) {
      data[i] += data[j];
      data[i] = data[i] % 1000007;
    }
  }
  
  printf("%d", data[n]);
  return 0;
}