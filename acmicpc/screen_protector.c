#include <stdio.h>

const int MAX = 20;

int data[MAX][MAX];
int solution[MAX];
int depth, width, k, flag;
int min_treated;

bool check() {
    int passed[MAX] = {0};
    for (int j = 0; j < width; j++) {
        int cnt = 1;
        for (int i = 0; i < depth - 1; i++) {
            if (depth - i < k && cnt == 1)
                return false;

            int current = solution[i] == 2 ? data[i][j] : solution[i];
            int next = solution[i + 1] == 2 ? data[i + 1][j] : solution[i + 1];
            
            if (current == next) {
                cnt++;
                if (cnt >= k) {
                    result[j] = 1;
                    break;
                }
            } else
                cnt = 1;
        }
        if (!passed[j])
            return false;
    }
    return true;
}

void solve(int y, int num_treated) {
    if (num_treated >= min_treated) {
        return;
    } else if (y >= depth) {
        if (check()) {
            if (num_treated < min_treated) {
                min_treated = num_treated;

                if (min_treated == 0) 
                    flag = 1;  
            }
        }
    } else {
        for (int i = 2; i >= 0; i--) {
            solution[y] = i;
            if (i < 2)
                solve(y + 1, num_treated + 1);
            else
                solve(y + 1, num_treated);
            if (flag == 1)
                return;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &depth, &width, &k);

        min_treated = depth, flag = 0;
        for (int i = 0; i < depth; i++) {
            for (int j = 0; j < width; j++) {
                scanf("%d", &data[i][j]);
            }
        }

        solve(0, 0);

        printf("#%d %d\n", tc, min_treated);
    }
    return 0;
}