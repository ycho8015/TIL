#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct vNode {
  int y;
  int x;
  int years;
};

const int MAX = 300;
vector<vNode> icebergs;
int map[MAX][MAX];
int visited[MAX][MAX];
int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};

int n, m, num_icebergs, years_passed = 1;

bool comp(vNode a, vNode b) {
  return a.years < b.years;
}

bool isBoundary(int y, int x) {
  return y >= 0 && x >= 0 && y < n && x < m;
}

int solve() {
  while (true) {
    for (int i = 0; i < icebergs.size(); i++) {
      int y = icebergs[i].y;
      int x = icebergs[i].x;
      int years = icebergs[i].years;
      
      int count = 0;
      for (int j = 0; j < 4; j++) {
        int ny = y + direction[0][j];
        int nx = x + direction[1][j];
        
        if (isBoundary(ny, nx)) {
          if (map[ny][nx] == 0)
            count++;
        }
      }
      icebergs[i].years = years - count;
    }
    
    for (int i = 0; i < icebergs.size(); i++) {
      int y = icebergs[i].y;
      int x = icebergs[i].x;
      int years = icebergs[i].years;
      
      if (years <= 0)
        map[y][x] = 0;
      else
        map[y][x] = years;
    }

    for (vector<vNode>::iterator iter = icebergs.begin(); iter != icebergs.end(); ) {
      if ((*iter).years <= 0)
        iter = icebergs.erase(iter);
      else
        iter++;
    }
    
    sort(icebergs.begin(), icebergs.end(), comp);
    
    int num_icebergs = icebergs.size();
    if (num_icebergs == 0) {
      return 0;
    }
    
    int visited[MAX][MAX] = {0};
    
    queue <pair<int, int>> q;
    q.push( {icebergs[0].y, icebergs[0].x} );
    
    int visited_icebergs = 0;
    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + direction[0][i];
        int nx = x + direction[1][i];
        
        if (isBoundary(ny, nx) && !visited[ny][nx] && map[ny][nx]) {
          visited[ny][nx] = 1;
          q.push( {ny, nx} );
          visited_icebergs++;
        }
      }
    }
    if (visited_icebergs != num_icebergs)
      return years_passed;
    years_passed++;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] > 0) 
        icebergs.push_back( {i, j, map[i][j]} );
    }
  }
  
  sort(icebergs.begin(), icebergs.end(), comp);
  
  int num_years = solve();
  printf("%d", num_years);
  
  return 0;
}