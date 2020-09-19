#include <stdio.h>

const int MAX = 10;

int map[MAX][MAX];
int check[MAX][MAX];
int n, max_cnt = 0;

bool isValid(int y, int x) {
  if (y < 2) 
    return true;
  
  for (int i = 1; i < y; i++) {
    for (int j = 1; j <= n; j++) {
      if (check[i][j] == 0 || map[i][j] == 0) continue;
      int rise = y - i;
      int run = check[y][x] - check[i][j] > 0 ? check[y][x] - check[i][j] : (-1) * (check[y][x] - check[i][j]);
      if (rise == run)
        return false;
    }
  }
  return true;
}

void DFS(int y, int x, int cnt) {
  if (y >= n + 1) {
    if (cnt > max_cnt)
      max_cnt = cnt;
  } else {
    if (x <= n) {
      if (map[y][x] == 1) {
        check[y][x] = x;
        if (isValid(y, x)) {
          DFS(y, x + 2, cnt + 1);
          check[y][x] = 0;
          DFS(y, x + 2, cnt);
        } else {
          check[y][x] = 0;
          DFS(y, x + 2, cnt);
        }
      } else {
        DFS(y, x + 2, cnt);
      }
    } else {
      if (n % 2 == 0) {
        if (x % n == 1) 
          DFS(y + 1, (x % n) + 1, cnt);
        else
          DFS(y + 1, (x % n) - 1, cnt);
      } else {
        DFS(y + 1, x % n, cnt);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  int sum = 0;
  DFS(1, 1, 0);
  sum += max_cnt;
  
  max_cnt = 0;
  
  DFS(1, 2, 0);
  sum += max_cnt;

  printf("%d", sum);  
  return 0;
}