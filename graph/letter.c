#include <stdio.h>

const int MAX = 30;
const int kMAX = 'Z' + 1;
int map[MAX][MAX];
int visited[kMAX];
int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};

int n, m, max_dist;

bool isValid(int y, int x, int alphabet) {
  if (y >= 0 && x >= 0 && y < n && x < m) {
    if (!visited[alphabet]) 
      return true;
  }
  return false;
}

void DFS(int y, int x, int dist) {
  int alphabet = map[y][x];
  visited[alphabet] = 1;
  
  if (dist > max_dist)
      max_dist = dist;
      
  for (int i = 0; i < 4; i++) {
    int ny = y + direction[0][i];
    int nx = x + direction[1][i];
    
    if (isValid(ny, nx, map[ny][nx])) {
      DFS(ny, nx, dist + 1);
    }
  }
  visited[alphabet] = 0;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &map[i][j]);
    }
  }
  
  DFS(0, 0, 1);

  printf("%d", max_dist);
  return 0;
}