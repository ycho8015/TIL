#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct cell {
    int y;
    int x;
    int hp;
    int max_hp;
};

const int MAX = 1000;
vector<cell> stems;

int map[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int n, m, k;

bool comp(cell a, cell b) {
    if (a.life < b.life) {
        return true;
    } else if (a.life == b.life) {
        if (a.max_life > b.max_life) {
            return true;
        }
    }
    return false;
}

bool isValid(int y, int x) {
    if (y >= 0 && x >= 0 && y < n && x < m) {
        if (!visited[y][x])
            return true;
    }
    return false;
}

void BFS() {
    while (k--) {
        sort(stems.begin(), stems.end(), comp);
        for (int i = 0; i < stems.size(); i++) {
            stems[i].hp -= 1;
            if (stems[i].hp == -1) {
                for (int j = 0; j < 4; j++) {
                    int ny = stems[i].y + dy[j];
                    int nx = stems[i].x + dx[j];
                    int max_hp = stems[i].max_hp;
                    if (isValid(ny, nx)) {
                        visited[ny][nx] = 1;
                        stems[i].push_back( {ny, nx, max_hp, max_hp} );
                    }
                }
            }
        }

        for (vector<cells>::Iterator iter = stems.begin(); iter != stems.end(); ) {
            if ((*iter).hp * (-1) == (*iter).max_hp) {
                iter = stems.erase(iter);
            } else {
                iter++;
            }
        }
    }
    memset(visited, 0 , sizeof(visited));
}

int main() {
    freopen("/Users/yoon/OneDrive/Workspace/algorithms/acmicpc/sample_input.txt", "r", stdin);
    freopen("/Users/yoon/OneDrive/Workspace/algorithms/acmicpc/output.txt", "w", stdout);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i + 500][j + 500]);
                if (map[i + 500][j + 500] > 0) {
                    stems.push_back( {i + 500, j + j, map[i + 500][j + 500], map[i + 500][j + 500]} );
                    visited[i + 500][j + 500] = 1;
                }
            }
        }
        BFS();

        printf("#%d %d\n", tc, stems.size());
    }
    return 0;
}