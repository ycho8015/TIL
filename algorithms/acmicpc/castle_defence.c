#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 15;

struct Point {
  int y;
  int x;
  int life;
};

vector<Point> v;
vector<Point> w;

int map[MAX][MAX];
int check[MAX];

int N, M, D;
int enemy, maxCnt;

int abs(int a) {
  return a > 0 ? a : (-1) * a;
}

int manhattan(int y1, int x1, int y2, int x2) {
  return abs(y1 - y2) + abs(x1 - x2);
}

int play() {
  vector<Point> temp;
  int killed = 0;
  temp.assign(w.begin(), w.end());

  while(true) {
    vector<int> killable;
    for (int i = 0; i < v.size(); i++) {
      int min_dist = 99999;
      int left_most = 99999;
      int idx = -1;
      for (int j = 0; j < temp.size(); j++) {
        int dist = manhattan(temp[j].y, temp[j].x , v[i].y, v[i].x);

        if (dist <= D) {
          if (min_dist > dist) {
            min_dist = dist;
            left_most = temp[j].x;
            idx = j;
          } else if (min_dist == dist) {
            if (left_most > temp[j].x) {
              idx = j;
              left_most = temp[j].x;
            }
          }
        }
      }
      if (idx != -1)
        killable.push_back(idx);
    }

    for (int i = 0; i < killable.size(); i++) {
      if (temp[killable[i]].life == 1) {
        temp[killable[i]].life = 0;
        killed++;
      }
    }

    for (int i = 0; i < temp.size(); i++) {
      temp[i].y += 1;
    }

    for (vector<Point>::iterator iter = temp.begin(); iter != temp.end(); ) {
      if ((*iter).life == 0 || (*iter).y >= N) {
        iter = temp.erase(iter);
      } else {
        iter++;
      }
    }

    if (temp.size() == 0)
      return killed;
  }
}

void solve(int y) {
  if (y >= 3) {
    
    int cnt = play();
    if (cnt >= maxCnt)
      maxCnt = cnt;
  } else {
    for (int i = 0; i < M; i++) {
      if (!check[i]) {
        check[i] = 1;
        v.push_back( {N, i, 0} );
        solve(y + 1);
        check[i] = 0;
        v.pop_back();
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &D);
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j])
        w.push_back({i, j, 1});
    }
  }

  solve(0);
  printf("%d\n", maxCnt);

  return 0;
}
