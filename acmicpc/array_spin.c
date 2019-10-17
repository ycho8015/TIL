#include <stdio.h>
#include <string.h>
#define MAX 51

struct Spin {
    int row;
    int col;
    int range;
};

Spin spin[6];
int map[MAX][MAX][2];
int check[6];
int order[6];
int n, m, k, min_sum = 99999;
void printArray() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", map[i][j][1]);
        }
        printf("\n");
    }
    printf("\n");
}

void copyMap() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[i][j][1] = map[i][j][0];
        }
    }
}
void solve() {
    copyMap();
    for (int len = 0; len < k; len++) {
        int row = spin[order[len]].row;
        int col = spin[order[len]].col;
        int range = spin[order[len]].range;

        
        for (int layer = 1; layer <= range; layer++) {
            int temp = map[row - layer][col - layer][1];

            for (int i = row - layer; i < row + layer; i++) {
                map[i][col - layer][1] = map[i + 1][col - layer][1];
            }

            for (int j = col - layer; j < col + layer; j++) {
                map[row + layer][j][1] = map[row + layer][j + 1][1];
            }

            for (int i = row + layer; i > row - layer; i--) {
                map[i][col + layer][1] = map[i - 1][col + layer][1];
            }

            for (int j = col + layer; j > col - layer; j--) {
                map[row - layer][j][1] = map[row - layer][j - 1][1];
            }

            map[row - layer][col - layer + 1][1] = temp;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += map[i][j][1];
        }
        if (min_sum > sum) {
            min_sum = sum;
        }
    }
}

void go(int z) {
    if (z >= k) {
        solve();
    } else {
        for (int i = 0; i < k; i++) {
            if (!check[i]) {
                check[i] = 1;
                order[z] = i;
                go(z + 1);
                check[i] = 0;
                order[z] = 0;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &map[i][j][0]);
            }
        }
    
        for (int i = 0; i < k; i++) {
            scanf("%d %d %d", &spin[i].row, &spin[i].col, &spin[i].range);
        }

        go(0);
        printf("#%d %d\n", tc, min_sum);
        min_sum = 999999;
        
    }
    return 0;
}