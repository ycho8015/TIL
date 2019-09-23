#include <stdio.h>
const int MAX = 1000;
int map[MAX][MAX];
int seq[MAX];
int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d ", &map[i][j]);
    }
  }
  
  seq[0] = (map[0][1] + (map[0][2] - map[1][2])) / 2; 
  
  for (int i = 1; i < n; i++) {
    seq[i] = map[0][i] - seq[0];
  }
  
  for (int i = 0; i < n; i++) {
    printf("%d ", seq[i]);
  }
  
  return 0;
}