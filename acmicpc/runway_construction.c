#include <cstdio>
using namespace std;

const int MAX = 20;

int map[MAX][MAX];
int n, length;

int abs(int a, int b) {
    return a - b > 0 ? a - b : (-1) * (a - b);
}

bool isBoundary(int x) {
    return x >= 0 && x < n;
}

bool isValid(int runway[], int s, int e) {

    if (!isBoundary(s) || !isBoundary(e)) return false;

    for (int i = s; i < e; i++) {
        if (runway[i] != runway[i + 1]) 
            return false;
    }
    return true;
}

bool isPossible(int runway[]) {
    for (int i = 1; i < n; i++) {
        if (abs(runway[i], runway[i - 1]) > 1)
            return false;
    }

    int front[MAX] = {0};
    int rear[MAX] = {0};

    for (int i = 0; i < n - 1; i++) {
        
        if (runway[i] == runway[i + 1]) continue;       // plain

        if (runway[i] + 1 == runway[i + 1]) {           // left to right
            int s = i - length + 1;
            int e = i;

            if (isValid(runway, s, e)) {
                for (int i = s; i <= e; i++) {
                    front[i] = 1;
                }
            } else {
                return false;
            }
        } else if (runway[i] - 1 == runway[i + 1]) {    // right to left
            int s = i + 1;
            int e = i + length;

            if (isValid(runway, s, e)) {
                for (int i = s; i <= e; i++) {
                    rear[i] = 1;
                }
            } else {
                return false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (front[i] && rear[i])
            return false;
    }
    return true;
}

int solve() {
    int num_possible = 0;
    int runway[MAX] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            runway[j] = map[i][j];
        }

        if (isPossible(runway)) num_possible++;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            runway[i] = map[i][j];
        }

        if (isPossible(runway)) num_possible++;
    }
    return num_possible;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &n, &length);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        int num_possible = solve();

        printf("#%d %d\n", tc, num_possible);
    }
    return 0;
}