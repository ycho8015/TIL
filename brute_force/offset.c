#include <stdio.h>
#include <stdbool.h>

int arr[5][5][2];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};

bool isBoundary(int y, int x) {
  return y >= 0 && y < 5 && x >= 0 && x < 5;
}

bool isPromising(int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dydx[0][i];
    int nx = x + dydx[1][i];
    
    if (isBoundary(ny, nx)) {
      if (arr[ny][nx][0] <= arr[y][x][0]) {
        return false;
      } 
    }
  }  
  return true;
}
int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d ", &arr[i][j][0]);
    }
  }
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if(isPromising(i, j)) {
        arr[i][j][1] = 1;
      }
    }
  }
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (arr[i][j][1] == 1) {
        printf("* ");
      } else {
        printf("%d ", arr[i][j][0]);
      }
    }
    printf("\n");
  }
  return 0;
}