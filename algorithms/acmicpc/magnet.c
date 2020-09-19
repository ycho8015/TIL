#include <stdio.h>
const int MAX = 20;
int magnet[4][8];
int instruction[2][MAX];
int num_spin;

void spin(int clock[]) {
    for (int i = 0; i < 4; i++) {
        if (clock[i] == 1) {
            int val = magnet[i][7];
            for (int j = 7; j > 0; j--) {
                magnet[i][j] = magnet[i][j - 1];
            }
            magnet[i][0] = val;
        } else if (clock[i] == -1) {
            int val = magnet[i][0];
            for (int j = 0; j < 7; j++) {
                magnet[i][j] = magnet[i][j + 1];
            }
            magnet[i][7] = val;
        }
    }
}

int solve() {
    for (int k = 0; k < num_spin; k++) {
        int clock[4] = {0};
        int which = instruction[0][k];
        int direction = instruction[1][k];
        clock[which] = direction;

        int idx = which - 1;
        int flag = 0;
        while (idx >= 0) {
            if (idx == 0) {
                if (magnet[0][2] != magnet[1][6] && clock[1] != 0) 
                    clock[0] = clock[1] * -1;
            } else {
                if (magnet[idx][2] != magnet[idx + 1][6] && clock[idx +1] != 0)
                    clock[idx] = clock[idx + 1] * -1;            
            }
            idx--;
        }

        idx = which + 1;
        while (idx < 4) {
            if (idx == 3) {
                if (magnet[3][6] != magnet[2][2] && clock[2] != 0)
                    clock[3] = clock[2] * -1;
            } else {
                if (magnet[idx - 1][2] != magnet[idx][6] && clock[idx -1] != 0)
                    clock[idx] = clock[idx - 1] * - 1;
            }
            idx++;
        }
        spin(clock);
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (magnet[i][0]) {
            int score = 1;
            for (int j = 0; j < i; j++) {
                score *= 2;
            }
            sum += score;
        }
    }
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &num_spin);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                scanf("%d", &magnet[i][j]);
            }
        }

        for (int i = 0; i < num_spin; i++) {
            scanf("%d %d", &instruction[0][i], &instruction[1][i]);
            instruction[0][i] -= 1;
        }

        int sum = solve();
        printf("#%d %d\n", tc, sum);
    }
    return 0;
}