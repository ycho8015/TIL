#include <stdio.h>
const int kMAX = 100005;

int max(int a, int b) {
  return a > b ? a : b;
}
int main() {
  int n;
  scanf("%d", &n);
  
  int data[kMAX][3] = {0};
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < 3; j++)
      scanf("%d", &data[i][j]);
  
  int result[kMAX][3];
  result[0][0] = data[0][0];
  result[0][1] = data[0][1];
  result[0][2] = data[0][2];
  
  for (int i = 1; i < n; i++) {
    result[i][0] = max(result[i - 1][0], max(data[i][0] + result[i - 1][1], data[i][0] + result[i - 1][2]));
    result[i][1] = max(result[i - 1][1], max(data[i][1] + result[i - 1][0], data[i][1] + result[i - 1][2]));
    result[i][2] = max(result[i - 1][2], max(data[i][2] + result[i - 1][0], data[i][2] + result[i - 1][1]));
  }
  
  printf("%d", max(result[n - 1][0], max(result[n - 1][1], result[n - 1][2])));
  return 0;
}