#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
const int MAX = 50;

struct Point {
    int y;
    int x;
    int average;
};

int map[MAX][MAX];
int visited[MAX][MAX];
int dydx[2][4]
={
    {-1, 1, 0, 0},
    {0, 0, 1, -1}
};
int n, low, high;

int abs(int a) {
    return a > 0 ? a : (-1) * a;
}

bool isBoundary(int y, int x) {
    return y >= 0 && x >= 0 && y < n && x < n;
}

void BFS(int y, int x, int group) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push( {y, x} );
    v.push_back( {y, x} );

    int cnt = 1;
    int sum = map[y][x];
    visited[y][x] = group;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dydx[0][i];
            int nx = x + dydx[1][i];

            if (isBoundary(ny, nx)) {
                if (visited[ny][nx] == 0) {
                    int diff = abs(map[y][x] - map[ny][nx]);
                    if (diff >= low && diff <= high) {
                        q.push( {ny, nx} );
                        v.push_back( {ny, nx} );
                        visited[ny][nx] = group;
                        sum += map[ny][nx];
                        cnt++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        map[v[i].first][v[i].second] = sum / cnt;
    }
}

int main() {
    scanf("%d %d %d", &n, &low, &high);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int num_migration = 0;
    while (true) {
        int group = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    BFS(i, j, ++group);
                }
            }
        }

        if (group == n * n)
            break;

        memset(visited, 0, sizeof(visited));

        num_migration++;   
    }
    printf("%d", num_migration);
    return 0;
}