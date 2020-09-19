#include <stdio.h>
char check[27];
char ans[27];

int n, r;

void getPermutation(int x) {
  if (x >= r) {
    for (int i = 0; i < r; i++) {
      printf("%c", ans[i]);
    }
    printf("\n");
  } else {
    for (int i = 0; i < n; i++) {
      if (check[i] == 0) {
        check[i] = 1;
        ans[x] = i + 'a';
        getPermutation(x + 1);
        check[i] = 0;
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &r);
  
  getPermutation(0);
  
  return 0;
}