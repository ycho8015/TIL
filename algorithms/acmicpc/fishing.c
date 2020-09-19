#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

const int MAX = 101;

struct Shark {
    int y;
    int x;
    int speed;
    int dir;
    int size;
    bool life;
} data[MAX*MAX];

int map[MAX][MAX];
int check[MAX][MAX][2];
int change[5] = {0, 2, 1, 4, 3};
int dydx[2][5]
={
    {0, -1, 1, 0, 0},
    {0, 0, 0, 1, -1}
};

int row, col, m, ans;

bool isBoundary(int y, int x) {
    return y >= 1 && x >= 1 && y <= row && x <= col;
}

void printArray() {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void updateMap() {
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= m; i++) {
        if (data[i].life == true) {
            int y = data[i].y;
            int x = data[i].x;
            int dir = data[i].dir;
            int speed = data[i].speed;
            int rotate = 0;
            if (dir == 1 || dir == 2) {
                rotate = (row - 1) * 2;
            } else {
                rotate = (col - 1) * 2;
            }
            if (speed >= rotate) speed = speed % rotate;
            for (int j = 0; j < speed; j++) {
                y += dydx[0][dir];
                x += dydx[1][dir];
                if (!isBoundary(y, x)) {
                    dir = change[dir];
                    y += dydx[0][dir] * 2;
                    x += dydx[1][dir] * 2;
                }
            }
            data[i].y = y;
            data[i].x = x;
            data[i].dir = dir;
            int size = data[i].size;
            if (map[y][x] > 0) {
                if (data[map[y][x]].size > size) {
                    data[i].life = false;
                } else {
                    data[map[y][x]].life = false;
                    map[y][x] = i;
                }
            } else {
                map[y][x] = i;
            }
        }
    }
}

void solve(int pos) {
    for (int j = 1; j <= row; j++) {
        int idx = map[j][pos];
        if (idx > 0) {
            ans += data[idx].size;
            data[idx].life = false;
            map[j][pos] = 0;
            break;
        }
    }
}

int main() {
    freopen("/Users/yoon/OneDrive/Workspace/algorithms/acmicpc/sample_input.txt", "r", stdin);
    freopen("/Users/yoon/OneDrive/Workspace/algorithms/acmicpc/output.txt", "w", stdout);
    scanf("%d %d %d", &row, &col, &m);

    if (m == 0) {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= m; i++) {   
        scanf("%d %d %d %d %d", &data[i].y, &data[i].x, &data[i].speed, &data[i].dir, &data[i].size);
        data[i].life = 1;
        map[data[i].y][data[i].x] = i;
    }
   // printArray();
    for (int i = 1; i <= col; i++) {
        solve(i);
        
        updateMap();
       // printArray();
    }


    printf("%d", ans);
    return 0;
}