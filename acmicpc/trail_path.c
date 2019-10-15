#include <stdio.h>
#define MAX 20

int map[MAX][MAX];
int visited[MAX][MAX];
int dydx[2][4]
={
    {-1, 1, 0, 0},
    {0, 0, 1, -1}
};

int n, k, max_height, max_dist;


bool isValid(int y, int x, int visited[][MAX]) {
    if (y >= 0 && x >= 0 && y < n && x < n) {
        if (!visited[y][x]) return true;
    }
    return false;
}


void solve(int y, int x, int height, int dist, int cut) {
    visited[y][x] = 1;

    if (dist > max_dist)
        max_dist = dist;

    for (int i = 0; i < 4; i++) {
        int ny = y + dydx[0][i];
        int nx = x + dydx[1][i];
        int next_height = map[ny][nx];

        if (isValid(ny, nx, visited)) {
            if (next_height < height) {
                solve(ny, nx, next_height, dist + 1, cut);
            } else if (next_height - k < height && !cut) {
                solve(ny, nx, height - 1, dist + 1, 1);
            } 
        }
    }
    visited[y][x] = 0;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j] > max_height)
                    max_height = map[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == max_height)
                    solve(i, j, max_height, 1, 0);
            }
        }
        printf("#%d %d\n", tc, max_dist);
        max_dist = 0, max_height = 0;
    }
    return 0;
}
    