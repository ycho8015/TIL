#include <stdio.h>
#include <stdbool.h>

int board[8][8];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};

bool isBoundary(int y, int x) {
  return y >= 0 && x >= 0 && y < 8 && x < 8;
}

bool solve(int y, int x, int dir) {
  int ny = y + dydx[0][dir];
  int nx = x + dydx[1][dir];
  
  if (isBoundary(ny, nx)) {
    if (board[ny][nx] == 2) {
      return true;
    } else if (board[ny][nx] == 0) {
      solve(ny, nx, dir);
    } else if (board[ny][nx] == 3) {
      return false;
    }
  }
}

int main(void) {
  int y, x;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      scanf("%d ", &board[i][j]);
      if (board[i][j] == 1) {
        y = i;
        x = j;
      }
    }
  }
  
  for (int i = 0; i < 4; i++) {
    if(solve(y, x, i)) {
      printf("1");
      return 0;
    }
  }
  
  printf("0");
  return 0;
}