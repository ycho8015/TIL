#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 50;

struct Point {
    int y;
    int x;
};

int map[MAX][MAX];
int visited[MAX][MAX];
int dydx[2][8][4]
={
    {
        {0, 0, 0, 0},
        {-1, 1, 0, 0},
        {-1, 1, 0, 0},
        {0, 0, 0, 0},
        {-1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {-1, 0, 0, 0}
    },
    {
        {0, 0, 0, 0},
        {0, 0, 1, -1},
        {0, 0, 0, 0},
        {0, 0, 1, -1},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, -1},
        {0, 0, 0, -1}
    }
};

int open[8][4]
={
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 0, 1}
};

int l, n, m, src_y, src_x, num_possible_loc;

bool isValid(int y, int x) {
    if (y >= 0 && x >= 0 && y < n && x < m) {
        if (map[y][x] != 0 && !visited[y][x])
            return true;
    }
    return false;
}

void solve() {
    queue <Point> q;
    q.push( {src_y, src_x} );
    visited[src_y][src_x] = 1;
    num_possible_loc++;

    int cnt = 1;
    while (cnt < l) {
        int size = (int)q.size();
        while (size--) {
            Point p = q.front();
            q.pop();

            int pipe = map[p.y][p.x];
            for (int i = 0; i < 4; i++) {
                int y = p.y + dydx[0][pipe][i];
                int x = p.x + dydx[1][pipe][i];
                int next_pipe = map[y][x];
                int path;
                if (i == 0) path = 1;
                else if (i == 1) path = 0;
                else if (i == 2) path = 3;
                else path = 2;

                if (isValid(y, x)) { 
                    if (open[next_pipe][path]) {
                        visited[y][x] = 1;
                        num_possible_loc++;
                        q.push( {y, x} );   
                    }
                }
            }                
        }
        cnt++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d %d %d", &n, &m, &src_y, &src_x, &l);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        num_possible_loc = 0;
        memset(visited, 0, sizeof(visited));
        solve();
        printf("#%d %d\n", tc, num_possible_loc);
    }
    return 0;
}