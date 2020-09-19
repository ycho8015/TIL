#include <stdio.h>
#include <string.h>
#define mMAX 20
#define kMAX 101

int map[mMAX][mMAX];
int visited[kMAX];
int n, max_dessert;

void solve(int y, int x) {
    for (int a = 1; a < n; a++) {
        for (int b = 1; b < n; b++) {
            if (x + a < n 
                && x - b >= 0
                && y + a + b < n
                && 2 * (a + b) > max_dessert)
            {
                memset(visited, 0, sizeof(visited));

                int cur_y = y, cur_x = x;
                for (int i = 0; i < a; i++) {
                    if (!visited[map[cur_y][cur_x]]) visited[map[cur_y][cur_x]] = 1;
                    else return;
                    cur_y++, cur_x++;
                }

                for (int i = 0; i < b; i++) {
                    if (!visited[map[cur_y][cur_x]]) visited[map[cur_y][cur_x]] = 1;
                    else return;
                    cur_y++, cur_x--;
                }

                for (int i = 0; i < a; i++) {
                    if (!visited[map[cur_y][cur_x]]) visited[map[cur_y][cur_x]] = 1;
                    else return;
                    cur_y--, cur_x--;
                }

                for (int i = 0; i < b; i++) {
                    if (!visited[map[cur_y][cur_x]]) visited[map[cur_y][cur_x]] = 1;
                    else return;
                    cur_y--, cur_x++;
                }

                max_dessert = 2 * (a + b);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);

        max_dessert = -1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                solve(i, j);
  
        printf("#%d %d\n", tc, max_dessert);
    }

    return 0;
}