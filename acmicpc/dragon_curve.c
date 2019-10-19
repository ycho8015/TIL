#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 101;

int visited[MAX][MAX];
int data[20][4];

int dydx[2][4]
={
    {0, -1, 0, 1},
    {1, 0, -1, 0}
};

vector<int> curve;
int n;

void solve() {
    for (int i = 0; i < n; i++) {
        int x = data[i][0];
        int y = data[i][1];
        int dir = data[i][2];
        int g = data[i][3];

        visited[y][x] = 1;
        y += dydx[0][dir];
        x += dydx[1][dir];
        visited[y][x] = 1;

        curve.push_back(dir);

        for (int j = 0; j < g; j++) {
            int size = curve.size();
            for (int k = size - 1; k >= 0; k--) {
                int ndir = (curve[k] + 1) % 4;
                y += dydx[0][ndir];
                x += dydx[1][ndir];
                visited[y][x] = 1;
                curve.push_back(ndir);
            }
        }
        curve.clear();
    }
}


int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i][0], &data[i][1], &data[i][2], &data[i][3]);
    }

    solve();
    
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (visited[i][j]) {
                if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
                    ans++;
            }
        }
    }

    printf("%d", ans);
    return 0;
}
