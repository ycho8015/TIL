#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 100;

struct Point {
  int y;
  int x;
  int build_time;
};

Point river;

int map[MAX][MAX];
int visited[MAX][MAX];
int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n, num_dam;

bool isValid(int y, int x, int type) {
  if (y >= 1 && x >= 1 && y <= n && x <= n) {
    if (!visited[y][x] && !map[y][x]) 
      return true;
  }
  return false;
}

void DAM() {
  queue<Point> q;
  q.push( {river.y, river.x, 0} );
  visited[river.y][river.x] = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().y;
      int x = q.front().x;
      int build_time = q.front().build_time;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
        int ny = y + direction[0][i];
        int nx = x + direction[1][i];
        
        if (isValid(ny, nx, map[ny][nx])) {
          visited[ny][nx] = build_time + 1;
          if (build_time + 1 == river.build_time)
            num_dam++;
          if (build_time + 1 < river.build_time)
            q.push( {ny, nx, build_time + 1});
        }
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  
  int num_path = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &map[i][j]);
      if (!map[i][j]) num_path++;
    }
  }
  scanf("%d %d\n%d", &river.x, &river.y, &river.build_time);
  
  DAM();
  if (num_dam == 0)
    printf("-1");
  else
    printf("%d", num_dam);
  
  return 0;
}