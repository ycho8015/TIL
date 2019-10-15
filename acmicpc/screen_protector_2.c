#include <stdio.h>
const int MAX = 20;

int film[MAX][MAX];
int chemical[MAX];
int depth, width, k;
int min_treated, flag;

void solve(int current_depth, int treated, int prev_continuum[], int prev_max_continuum[]) {
    if (treated >= min_treated) return;

    if (current_depth >= depth) {
        bool isPromising = true;
        for (int i = 0; i < width; i++) {
            if (prev_max_continuum[i] < k) return;
        }

        if (treated < min_treated) min_treated = treated;
        
        if (min_treated == 0) flag = 1;
    } else {
        int continuum[MAX];
        int max_continuum[MAX];
        int prev, cur;

        for (int i = 2; i >= 0; i--) {
            chemical[current_depth] = i;

            for (int j = 0; j < width; j++) { 
                cur = chemical[current_depth] == 2 ? film[current_depth][j] : chemical[current_depth];
                prev = chemical[current_depth - 1] == 2 ? film[current_depth - 1][j] : chemical[current_depth - 1];
                continuum[j] = cur == prev ? prev_continuum[j] + 1 : 1;

                max_continuum[j] = continuum[j] > prev_max_continuum[j] ? continuum[j] : prev_max_continuum[j];
            }

            solve(current_depth + 1, i == 2 ? treated : treated + 1, continuum, max_continuum);

            if (flag) return;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &depth, &width, &k);

        min_treated = k, flag = 0;
        for (int i = 0; i < depth; i++) {
            for (int j = 0; j < width; j++) {
                scanf("%d", &film[i][j]);
            }
        }

        int continuum[MAX] = {1};
        int max_continuum[MAX] = {1};

        for (int i = 2; i >= 0; i--) {
            chemical[0] = i;
            solve(1, i == 2 ? 0 : 1, continuum, max_continuum);
        }
        printf("#%d %d\n", tc, min_treated);
    }
    return 0;
}