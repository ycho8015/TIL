#include <cstdio>
#include <vector>
#include <string.h>
#include <limits.h>
using namespace std;

const int MAX = 12;

struct Point {
    int y;
    int x;
};

int map[MAX][MAX];
int dydx[2][4]
={
    {-1, 1, 0, 0},
    {0, 0, 1, -1}
};

int n, max_num_connected, min_length = INT_MAX;
vector<Point> v;

bool isBoundary(int y, int x) {
    return y >= 0 && x >= 0 && y < n && x < n;
}

void solve(int cnt, int num_connected, int current_length) {
    if (cnt >= v.size()) {
        if (num_connected > max_num_connected) {
            max_num_connected = num_connected;
            min_length = current_length;
        } else if (num_connected == max_num_connected) {
            if (current_length < min_length)
                min_length = current_length; 
        }
    } else {
        int y = v[cnt].y;
        int x = v[cnt].x;
        for (int j = 0; j < 4; j++) {
            int length = 0, flag = 0;
            int ny = y;
            int nx = x;
            while (true) {
                ny += dydx[0][j];
                nx += dydx[1][j];
                if (isBoundary(ny, nx)) {
                    if (map[ny][nx] == 0) {
                        length++;
                    } else {
                        break;
                    }
                } else {
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                int ny = y;
                int nx = x;
                for (int k = 0; k < length; k++) {
                    ny += dydx[0][j];
                    nx += dydx[1][j];
                    map[ny][nx] = 2;
                }

                solve(cnt + 1, num_connected + 1, current_length + length);

                ny = y;
                nx = x;
                for (int k = 0; k < length; k++) {
                    ny += dydx[0][j];
                    nx += dydx[1][j];
                    map[ny][nx] = 0; 
                }
            }
        }
        solve(cnt + 1, num_connected, current_length);
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
                if (map[i][j] == 1) {
                    if (i != 0 && i != n - 1 && j != 0 && j != n - 1) {
                        v.push_back( {i, j} );      
                    }
                }  
            }
        }
        
        solve(0, 0, 0);

        if (min_length == INT_MAX) 
            printf("#%d %d\n", tc, 0);
        else
            printf("#%d %d\n", tc, min_length);

        max_num_connected = 0;
        min_length = INT_MAX;
        v.clear();
    }
    return 0;
}