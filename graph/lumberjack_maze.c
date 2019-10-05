#include <cstdio>
#include <queue>
using namespace std;

typedef struct QueueNode {
  int y;
  int x;
  int dist;
  bool axe;
}qNode;

const int MAX = 1000;
int map[MAX][MAX];
int visited[MAX][MAX][2];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n, m;

bool isBoundary(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

int BFS() {
  queue <qNode> q;
  q.push( {n - 1, 0, 0, false} );
  visited[n - 1][0][0] = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().y;
      int x = q.front().x;
      int dist = q.front().dist;
      bool axe = q.front().axe;
      q.pop();
      
      if (y == 0 && x == m - 1)
        return dist;
        
      for (int i = 0; i < 4; i++) {
        int ny = y + dydx[0][i];
        int nx = x + dydx[1][i];
        
        if (isBoundary(ny, nx)) {
          if (axe) {
            if (map[ny][nx] == 0 && visited[ny][nx][0] == 0 && visited[ny][nx][1] == 0) {
              visited[ny][nx][1] = 1;
              q.push( {ny, nx, dist + 1, true} );
            }
          } else {
            if (map[ny][nx] == 0 && visited[ny][nx][0] == 0) {
              visited[ny][nx][0] = 1;
              q.push( {ny, nx, dist + 1, false} );
            } else if (map[ny][nx] == 1 && visited[ny][nx][0] == 0) {
              visited[ny][nx][0] = 1;
              q.push( {ny, nx, dist + 1, true} );
            }
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) 
      scanf("%d", &map[i][j]);
  
  int dist = BFS();
  printf("%d", dist);
  
  return 0;
}