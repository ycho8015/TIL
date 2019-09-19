#include <stdio.h>
#include <stdlib.h>

int manhattan(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int y, x, range;
    scanf("%d %d %d", &y, &x, &range);
    y -= 1;
    x -= 1;

    int map[100][100]={0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == y && j == x) continue;
            int dist = manhattan(y, x, i, j);
            if (dist <= range) {
                map[i][j] = dist;
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == y && j == x) {
                printf("x ");
            } else {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}