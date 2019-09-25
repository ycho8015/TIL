#include <stdio.h>
int n, cnt = 0;
int result[40];

void getDivision(int x, int sum) {
  if (sum == n) {
    printf("%d", result[0]);
    for (int i = 1; i < x; i++) {
      printf("+%d", result[i]);
    }
    cnt++;
    printf("\n");
  } else {
    int nextNum;
    if (x == 0) 
      nextNum = n - 1;
    else
      nextNum = n - sum;
    
    for (int i = nextNum; i >= 1; i--) {
      if (x != 0 && i > result[x - 1]) 
        continue;
        
      result[x] = i;
      sum += i;
      getDivision(x + 1, sum);
      sum -= i;
    }
  }
}

int main() {
  scanf("%d", &n);
  
  getDivision(0, 0);
  printf("%d", cnt);
  return 0;
}