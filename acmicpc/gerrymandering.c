#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
const int MAX = 11;

vector<int> v[MAX];
int cost[MAX];
int order[2][MAX];

int n, flag, ans = INT_MAX;

bool isPromising() {
    queue<int> q;
    int check[2][MAX] ={0};

    for (int i = 0; i < 2; i++) {
        for (int k = 1; k <= n; k++) {
            if (order[i][k]) {
                q.push(k);
                check[i][k] = 1;
                break;
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int j = 0; j < v[current].size(); j++) {
                int next = v[current][j];
                for (int k = 0; k < MAX; k++) {
                    if (order[i][next] && !check[i][next]) {
                        check[i][next] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (check[i][j] != order[i][j])
                return false;
        }
    }
    return true;
}

void solve(int y) {
    if (y > n) {
        if (isPromising()) {
            int sum[2] = {0};
            for (int i = 0; i < 2; i++) {
                for (int j = 1; j <= n; j++) {
                    if (order[i][j]) {
                        sum[i] += cost[j];
                    }
                }
            }
            int result = sum[0] - sum[1] > 0 ? sum[0] - sum[1] : (-1) * (sum[0] - sum[1]);
            if (result < ans) {
                ans = result;
                if (ans == 0)
                    flag = 1;
            }
        }
    } else {
        for (int i = 0; i < 2; i++) {
            order[i][y] = 1;
            solve(y + 1);
            order[i][y] = 0;
            if (flag)  
                return;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        if (num == 0) continue;
        for (int j = 0; j < num; j++) {
            int node;
            scanf("%d", &node);
            v[i].push_back(node);    
        }
    }

    solve(1);
    if (ans == INT_MAX) {
        printf("-1");
    } else {
        printf("%d", ans);
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%d: ", i);
    //     for (int j = 0; j < v[i].size(); j++) {
    //         printf("%d ", v[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
