#include <cstdio>
#include <queue>

using namespace std;

struct Point {
  int x;
  int y;
};

const int MAX = 101;
int map[MAX][MAX];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};

int n, m;

bool isValid(int visited[][MAX], int x, int y) {
  
  if (x >= 0 && y >= 0 && x < m && y < n) {
    if (!visited[y][x])
      return true;
  }
  return false;
}

int BFS() {
  int visited[MAX][MAX] = {0};
  int melted_cheese = 0;
  
  queue<Point> q;
  q.push( {0, 0} );
  visited[0][0] = 1;
  
  while(!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int x = q.front().x;
      int y = q.front().y;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
        int nx = x + dydx[1][i];
        int ny = y + dydx[0][i];
        
        if (isValid(visited, nx, ny)) {
          if (map[ny][nx] == 0) {
            visited[ny][nx] = 1;
            q.push( {nx, ny} );
          } else {
            visited[ny][nx] = 1;
            map[ny][nx] = 0;
            melted_cheese++;
          }
        }
      }
    }
  }
  return melted_cheese;
}
int main() {
  scanf("%d %d", &n, &m);
  
  int cheese = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 1)
        cheese++;
    }
  }
  
  int cheese_left = cheese, hours = 0;
  while (cheese != 0) {
    int melted_cheese = BFS();
    if (cheese - melted_cheese != 0)
      cheese_left -= melted_cheese;
    cheese -= melted_cheese;
    hours++;
  }
  
  printf("%d\n%d", hours, cheese_left);
  return 0;
}