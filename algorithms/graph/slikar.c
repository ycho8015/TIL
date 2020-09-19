#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

struct Point {
  int y;
  int x;
};

const int MAX = 51;
vector<Point> river;
int map[MAX][MAX];
int visited[MAX][MAX][2];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};

Point src;
int n, m;

bool isBoundary(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

int BFS(int which) {
  queue <Point> q;
  int hours = 1;
  if (which == 0) {
    for (int i = 0; i < river.size(); i++) {
      q.push(river[i]);
      visited[river[i].y][river[i].x][which] = hours;
    }
  } else {
    q.push(src);
    visited[src.y][src.x][which] = hours;
  }
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().y; 
      int x = q.front().x;
      q.pop();
      
      if (which == 1 && map[y][x] == 'D')
        return hours - 1;
        
      for (int i = 0; i < 4; i++) {
        int ny = y + dydx[0][i];
        int nx = x + dydx[1][i];
        
        if (isBoundary(ny, nx)) {
          if (which == 1) {
            if (!visited[ny][nx][which]) {
              if ((visited[ny][nx][0] > hours || visited[ny][nx][0] == 0) && (map[ny][nx] != 'X' && map[ny][nx] != '*')) {
                visited[ny][nx][which] = hours;
                q.push( {ny, nx} );
              }
            } 
          } else {
            if (!visited[ny][nx][which]) {
              if (map[ny][nx] != 'D' && map[ny][nx] != 'X') {
                visited[ny][nx][which] = hours;
                q.push( {ny, nx} );
              }
            }            
          }
        }
      }
    }
    hours++;
  }
  return 0;
}


int main() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &map[i][j]);
      if (map[i][j] == 'S') {
          src.y = i;
          src.x = j;
      } else if (map[i][j] == '*') {
        river.push_back( {i, j} );
      }
    }
  }
  
  int flood_path = BFS(0);
  int hedgehog_path = BFS(1);

  if (hedgehog_path == 0)
    printf("KAKTUS");
  else
    printf("%d", hedgehog_path);
    
  return 0;
}