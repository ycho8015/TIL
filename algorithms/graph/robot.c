#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 101;

struct Robot {
  int y;
  int x;
  int dir;
  int op;
};

Robot src, dest;

int map[MAX][MAX];
int visited[MAX][MAX][4];
int direction[2][5]
={
  {0, 0, 0, 1, -1},
  {0, 1, -1, 0, 0}
};

int dir_change[5][2]
={
  {0, 0},
  {4, 3},
  {3, 4},
  {1, 2},
  {2, 1},
};

int n, m;

bool isValid(int y, int x) {
  if (y >= 1 && x >= 1 && y <= n && x <= m) 
    if (!map[y][x])
      return true;
  return false;
}

int minOperation() {
  visited[src.y][src.x][src.dir] = 1;
  queue<Robot> q;
  q.push( {src.y, src.x, src.dir, src.op} );
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().y;
      int x = q.front().x;
      int dir = q.front().dir;
      int op = q.front().op;
      q.pop();
      
      if (y == dest.y && x == dest.x && dir == dest.dir)
        return op;
      
      for (int i = 1; i <= 3; i++) {
        int ny = y + direction[0][dir] * i;
        int nx = x + direction[1][dir] * i;
        
        if (isValid(ny, nx)) {
          if (!visited[ny][nx][dir]) {
            visited[ny][nx][dir] = 1;
            q.push( {ny, nx, dir, op + 1} );
          }
        } else {
          break;
        }
      }
      
      for (int i = 0; i < 2; i++) {
        int next_dir = dir_change[dir][i];

        if (!visited[y][x][next_dir]) {
          visited[y][x][next_dir] = 1;
          q.push( {y, x, next_dir, op + 1} );
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  scanf("%d %d %d", &src.y, &src.x, &src.dir);
  scanf("%d %d %d", &dest.y, &dest.x, &dest.dir);
  src.op = 0, dest.op = 0;
  
  int num_operations = minOperation();
  
  printf("%d", num_operations);
  return 0;
}