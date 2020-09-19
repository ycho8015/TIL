#include <stdio.h>
const int MAX = 17;
int map[MAX][MAX];
int dydx[3][2]
={
  {0, 1},
  {1, 0},
  {1, 1}
};

int n, num_possible;

bool isBoundary(int y, int x) {
  return y >= 1 && x >= 1 && y <= n && x <= n;
}

void solve(int y, int x, int pipe) {
  if (y >= n && x >= n) {
    num_possible++;
  } else {
    for (int i = 0; i < 3; i++) {
      if (pipe + i == 1) continue;
      int ny = y + dydx[0][i];
      int nx = x + dydx[1][i];

      if (isBoundary(ny, nx)) {
        if (i == 2) {
          if (!map[ny][nx - 1] && !map[ny][nx] && !map[ny - 1][nx])
            solve(ny, nx, i);
        } else if (!map[ny][nx]) {
            solve(ny, nx, i);
        }
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

  solve(1, 2, 0);
  printf("%d", num_possible);

  return 0;
}