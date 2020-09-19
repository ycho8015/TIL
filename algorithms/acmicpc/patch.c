#include <stdio.h>
#define MAX 10

int a[MAX][MAX];
int patch[6] = {0, 5, 5, 5, 5, 5};

int go(int z) {
  if (z == 100) {
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        if (a[i][j])
          return -1;
      }
    }
    return 0;
  } 

  int x = z % 10;
  int y = z / 10;

  if (!a[y][x]) {
    return go(z + 1);
  }

  int ans = -1;
  for (int k = 5; k >= 1; k--) {
    if (patch[k]) {
      if (x + k - 1 < 10 && y + k - 1 < 10) {
        bool ok = true;
        for (int i = y; i < y + k; i++) {
          for (int j = x; j < x + k; j++) {
            if (!a[i][j]) {
              ok = false; 
              break;
            }
          }
          if (!ok)
            break;  
        }
        if (ok) {
          for (int i = y; i < y + k; i++) {
            for (int j = x; j < x + k; j++) {
              a[i][j] = 0;
            }
          }
          patch[k] -= 1;
          int temp = go(z + 1);
          patch[k] += 1;
          if (temp != -1) {
            if (ans == -1 || ans > temp + 1) {
              ans = temp + 1;
            }
          }
          for (int i = y; i < y + k; i++) {
            for (int j = x; j < x + k; j++) {
              a[i][j] = 1;
            }
          }
        }
      }
    }
  }
  return ans;
}
int main () {
  int T;
  scanf("%d", &T);

  int n;
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &n);
    for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    int ans = go(0);
    printf("%d\n", ans);
  }
  return 0;
}