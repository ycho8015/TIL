#include <stdio.h>

// USACO 2002, poj 1950  
int n, cnt = 0;
int result[20];
int op[20];

void getDessert(int x) {
  if (x >= n - 1) {
    int copy[20];
    for (int i = 0; i < n; i++) {
      copy[i] = result[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
      if (op[i] == '.' && copy[i] != 0) {
        int idx = i + 1;
        while (1) {
          if (copy[idx] > 9) {
            copy[i] = copy[i] * 100 + copy[idx];
          } else {
            copy[i] = copy[i] * 10 + copy[idx];
          }
          copy[idx] = 0;
          if (op[idx] != '.')
            break;
          idx++;
        }
      }
    }
    
    for (int i = 0; i < n - 1; i++) {
      if (op[i] == '+') {
        copy[0] += copy[i + 1];
      } else if (op[i] == '-')
        copy[0] -= copy[i + 1];
    }
    
    if (copy[0] == 0) {
      cnt++;
      if (cnt <= 20) {
        for (int i = 0; i < n; i++) {
          printf("%d", result[i]);
          if (i < n - 1) {
            printf(" %c ", op[i]);
          }
        }
        printf("\n");
      }
    }
    
  } else {
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        op[x] = '+';
      } else if (i == 1) {
        op[x] = '-';
      } else {
        op[x] = '.';
      }
      getDessert(x + 1);
    }
  }
}

int main() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; i++) {
    result[i - 1] = i;
  }

  getDessert(0);
  printf("%d", cnt);
  
  return 0;
}