#include <cstdio>
#include <string.h>
using namespace std;

const int MAX = 101;
int map[MAX][MAX];
int visited[MAX][MAX];
int valid[MAX][MAX];

int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n;

bool isValid(int y, int x, int ny, int nx) {
  if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
    if (!visited[ny][nx] && valid[map[y][x]][map[ny][nx]]) {
      return true;
    }
  }
  return false;
}

void visit(int y, int x) {
  visited[y][x] = 1;
  
  for (int i = 0; i < 4; i++) {
    int ny = y + direction[0][i];
    int nx = x + direction[1][i];
    if (isValid(y, x, ny, nx)) {
      visit(ny, nx);
    }
  }
}

int solve() {
  int num_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        visit(i, j);
        num_area++;
      }
    }
  }
  memset(visited, 0, sizeof(visited));
  return num_area;
}

int main() {
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &map[i][j]);
    }
  }
  
  valid['R']['R'] = valid['G']['G'] = valid['B']['B'] = true;
  int human = solve();
  valid['R']['G'] = valid['G']['R'] = true;
  int cow = solve();
  
  printf("%d %d", human, cow);
  return 0;
}