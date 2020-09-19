    #include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1005;

typedef struct QueueNode {
  int y;
  int x;
  int dist;
}qNode;

int map[MAX][MAX];
int visited[MAX][MAX];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n, m;

bool isValid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < m)
    if (!map[y][x] && !visited[y][x])
      return true;
  return false;
}

void BFS() {
  queue <qNode> q;
  q.push( {n - 1, 0, 0} );
  visited[n - 1][0] = 0;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().y;
      int x = q.front().x;
      int dist = q.front().dist;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
        int ny = y + dydx[0][i];
        int nx = x + dydx[1][i];
        
        if (isValid(ny, nx)) {
          visited[ny][nx] = dist + 1;
          q.push( {ny, nx, dist + 1} );
        }
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  BFS();

  printf("%d", visited[0][m - 1]);
  
  return 0;
}