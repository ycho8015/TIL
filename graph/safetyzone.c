#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 100;
int map[MAX][MAX];
int visited[MAX][MAX];
int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n, max_zone;

bool isBoundary(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < n;
}

int BFS() {
  for (int height = 1; height <= 100; height++) {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map[i][j] <= height) {
          visited[i][j] = 1;
        }
      }
    }
    
    int zone = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          zone++;
          queue<pair<int,int>> q;
          q.push( {i, j} );
          visited[i][j] = 1;
          
          while (!q.empty()) {
            int size = (int)q.size();
            while (size--) {
              int y = q.front().first;
              int x = q.front().second;
              q.pop();
              
              for (int i = 0; i < 4; i++) {
                int ny = y + direction[0][i];
                int nx = x + direction[1][i];
                
                if (isBoundary(ny, nx) && !visited[ny][nx]) {
                  visited[ny][nx] = 1;
                  q.push( {ny, nx } );
                }
              }
            }
          }
        }
      }
    }
   max_zone = zone > max_zone ? zone : max_zone; 
  }
  return max_zone;
}

int main() {
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  
  int num_zone = BFS();
  printf("%d", num_zone);

  return 0;
}