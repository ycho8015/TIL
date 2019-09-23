#include <stdio.h>
const int MAX = 101;
int data[MAX][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d ", &data[i][0]);
  }
  
  int sum = data[0][0];
  
  for (int i = 1; i <= n; i++) {
    data[i][1] = data[i][0] * i - sum;
    sum += data[i][1];
  }
  
  for (int i = 1; i <= n; i++) {
    printf("%d ", data[i][1]);
  }
  return 0;
}