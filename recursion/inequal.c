#include <stdio.h>
int n;
int inequal[10];
int result[10];
int min[10];
int check[10];
int flag;
void getInequal(int x) {
  if (x > n) {
    if (flag == 0) {
      for (int i = 0; i <= n; i++) {
        printf("%d", result[i]);
      }
      printf("\n");
      flag = 1;
    } else {
      for (int i = 0; i <= n; i++) {
        min[i] = result[i];
      }
    }
  } else {
    for (int i = 9; i >= 0; i--) {
      if (check[i] == 0) {
        if (x == 0) {
          check[i] = 1;
          result[x] = i;
          getInequal(x + 1);
          check[i] = 0;
          continue;
        } else if (inequal[x - 1] == '<' && result[x - 1] > i) {
            continue;
            
        } else if (inequal[x - 1] == '>' && result[x - 1] < i) {
            continue;
        }
        check[i] = 1;
        result[x] = i;
        getInequal(x + 1);
        check[i] = 0;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf(" %c", &inequal[i]);
  }

  getInequal(0);
  for (int i = 0; i <= n; i++) {
    printf("%d", min[i]);
  }
  return 0;
}