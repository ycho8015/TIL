#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 51;

int map[MAX][MAX];
int visited[MAX][MAX];
int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n, m, max_dist;

queue<pair<int,int>> q;

bool isValid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < m) {
    if (!visited[y][x] && map[y][x] == 'L')
      return true;
  }
  return false;
}

int BFS(int y, int x) {
  int dist = 0;
  visited[y][x] = 1;
  
  queue <pair<int, int>> q;
  q.push( {y, x} );
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
        int ny = y + direction[0][i];
        int nx = x + direction[1][i];
        
        if (isValid(ny, nx)) {
          visited[ny][nx] = 1;
          q.push( {ny, nx} );
        }
      }
    }
    dist++;
  }
  return dist - 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &map[i][j]);
      if (map[i][j] == 'L')
        q.push( {i, j} );
    }
  }
  
  int path = 0;
  int size = (int)q.size(); 
  for (int i = 0; i < size; i++) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    
    int dist = BFS(y, x);
    
    if (dist > path) 
      path = dist;
    memset(visited, 0, sizeof(visited));
  }
  
  printf("%d", path);
  return 0;
}