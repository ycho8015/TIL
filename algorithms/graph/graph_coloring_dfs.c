#include <cstdio>
#include <algorithm>

using namespace std;

int map[25][25];
int visited[25][25];
int dydx[2][4]
={
  {-1, 1, 0 ,0},
  {0, 0, 1, -1}
};

int n, group_cnt, group = 1;

bool isValid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < n) {
    if (!visited[y][x] && map[y][x] == '1')
      return true;
  }
  return false;
}

void DFS(int y, int x) {
  visited[y][x] = group;
  group_cnt++;
  for (int i = 0; i < 4; i++) {
    int ny = y + dydx[0][i];
    int nx = x + dydx[1][i];
    
    if (isValid(ny, nx))
      DFS(ny, nx);
  }
}

int main() {
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
      scanf(" %c", &map[i][j]);
      
  int result[100] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == '1' && visited[i][j] == 0) {
        DFS(i, j);
        result[group] = group_cnt;
        group_cnt = 0;
        group++;
        
      }
    }
  }
  
  sort(result, result + group);
  printf("%d\n",group - 1);
  for (int i = 1; i < group; i++)
    printf("%d\n", result[i]);
  
  return 0;
}