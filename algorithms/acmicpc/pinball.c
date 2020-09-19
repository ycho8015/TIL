#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 101;

struct vNode {
    int y;
    int x;
};

vector<vNode> black_hole;
vector<vNode> worm_hole[5];

int map[MAX][MAX];
int direction[2][4]
={
    {-1, 1, 0, 0},
    {0, 0, 1, -1}
};

int dydx[6][4]
={
    {0, 0, 0, 0},
    {1, 2, 3, 0},
    {2, 0, 3, 1},
    {3, 0, 1, 2},
    {1, 3, 0, 2},
    {1, 0, 3, 2}
};

int n, result;
int start_y, start_x;

bool isBoundary(int y, int x) {
    return y >= 0 && x >= 0 && y < n && x < n;
}

void DFS(int y, int x, int dir, int score) {
    if (score > result)
        result = score;

    int ny = y + direction[0][dir];
    int nx = x + direction[1][dir];

    if (!isBoundary(ny, nx)) {
        score = 2 * score + 1;
        if (score > result)
            result = score;
        return;
    }

    if (map[ny][nx] == -1)
        return;

    if (ny == start_y && nx == start_x)
        return;

    if (isBoundary(ny, nx)) {
        if (map[ny][nx] == 0) {
            DFS(ny, nx, dir, score);
        } else if (map[ny][nx] >= 1 && map[ny][nx] <= 5) {
            int new_dir = dydx[map[ny][nx]][dir];
            DFS(ny, nx, new_dir, score + 1);
        } else if (map[ny][nx] >= 6 && map[ny][nx] <= 10) {
            int num = map[ny][nx] - 6;
            if (worm_hole[num].at(0).y == ny && worm_hole[num].at(0).x == nx) {
                DFS(worm_hole[num].at(1).y, worm_hole[num].at(1).x, dir, score);
            } else {
                DFS(worm_hole[num].at(0).y, worm_hole[num].at(0).x, dir, score);
            }
        }
    }

}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j] >= 1 && map[i][j] <= 5)
                    black_hole.push_back( {i, j} );
                if (map[i][j] >= 6 && map[i][j] <= 10) {
                    worm_hole[map[i][j] - 6].push_back( {i, j} );
                }
            }   
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        start_y = i;
                        start_x = j;
                        DFS(i, j, k, 0);
                    }
                }
            }
        }

        printf("#%d %d\n", tc, result);
        memset(visited, 0, sizeof(visited));
        memset(map, 0, sizeof(map));
        result = 0;
        black_hole.clear();
        for (int i = 0; i < 5; i++) {
            worm_hole[i].clear();
        }
    }
    return 0;
}