#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Point {
  int y;
  int x;
  int z;
};

const int MAX = 100;

queue<Point> tomatoes;

int box[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int direction[3][6]
={
  {-1, 1, 0, 0, 0, 0},
  {0, 0, 1, -1, 0, 0},
  {0, 0, 0, 0, -1, 1}
};
int n, m, h, empty;

bool isValid(int y, int x, int z) {
  if (x >= 0 && y >= 0 && z >= 0 && x < m && y < n && z < h) {
    if (!visited[y][x][z] && !box[y][x][z])
      return true;
  }
  return false;
}

int BFS() {
  int days = 0;
  while (!tomatoes.empty()) {
    int size = (int)tomatoes.size();
    while (size--) {
      int y = tomatoes.front().y;
      int x = tomatoes.front().x;
      int z = tomatoes.front().z;
      tomatoes.pop();
      
      for (int i = 0; i < 6; i++) {
        int ny = y + direction[0][i];
        int nx = x + direction[1][i];
        int nz = z + direction[2][i];
        
        if (isValid(ny, nx, nz)) {
          visited[ny][nx][nz] = 1;
          tomatoes.push( {ny, nx, nz} );
          empty--;
        }
      }
    }
    days++;
  }
  return days - 1;
}

int main() {
  scanf("%d %d %d", &m, &n, &h);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        scanf("%d", &box[j][k][i]);
        if (box[j][k][i] == 1) {
          tomatoes.push( {j,k,i} );
          visited[j][k][i] = 1;
        } else if (box[j][k][i] == 0) {
          empty++;
        }
      }
    }
  }
  
  if (!empty) {
    printf("0");
    return 0;
  }
  
  int days = BFS();
  
  if (empty) {
    printf("-1");
    return 0;
  }
  
  printf("%d", days);
  return 0;
}