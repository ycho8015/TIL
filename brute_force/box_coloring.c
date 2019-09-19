#include <stdio.h>

int main() {
  int n, arr[1001][2]={0};
  
  scanf("%d ", &n);
  
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d ", &num);
    if (arr[num][1] >= 2) {
      continue;
    }
    arr[num][1] += 1;
  }
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i][1] > 0) {
      cnt += arr[i][1];
      
      if (cnt >= 6) {
        printf("YES");
        return 0;
      }
    }
  }
  
  if (cnt < 6) {
    printf("NO");
  }
  
  return 0;
}