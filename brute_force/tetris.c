#include <stdio.h>
#define MAX 20

int map[MAX][MAX];
int row, col, max_lines = 0, max_col = 0;

void solve(int x) {
  int cnt = 0;
  for (int i = 0; i < row; i++) {
    if (map[i][x] == 0) {
      cnt++;
    } else {
      break;
    }
  }
  
  if (cnt >= 4) {
    for (int i = 0; i < 4; i++) {
      map[cnt - 1 - i][x] = 1;
    }
  } else {
    return;
  }
  
  int lines = 0;
  for (int i = 0; i < row; i++) {
    int flag = 0;
    for (int j = 0; j < col; j++) {
      if (map[i][j] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      lines++;
  }
  
  if (lines > max_lines) {
    max_lines = lines;
    max_col = x;
  }
  
  for (int i = 0; i < 4; i++) {
    map[cnt - 1 - i][x] = 0;
  }
}

int main() {
  scanf("%d %d", &col, &row);
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d ", &map[i][j]);
    }
  }
  
  for (int j = 0; j < col; j++) {
    solve(j);
  }
  
  if (max_col == 0 && max_lines == 0)
    printf("0 0");
  else
    printf("%d %d", max_col + 1, max_lines);
    
  return 0;
}