#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 500;

int data[MAX];
int output[MAX];
int n, k;

bool comp(int a, int b) {
    return a > b;
}

int HextoDec(int num, int digit, int length) {
    if (num >= 'A')
        num = num - 'A' + 10;
    else
        num = num - '0';

    digit = length - 1 - digit;
    for (int i = 0; i < digit; i++) {
        num *= 16;
    }

    return num;
}

int main() {
    freopen("/Users/yoon/OneDrive/Workspace/algorithms/acmicpc/sample_input.txt", "r", stdin);
    freopen("/Users/yoon/OneDrive/Workspace/algorithms/acmicpc/output.txt", "w", stdout);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf(" %c", &data[i]);

        int num_spin = n / 4 - 1;

        for (int i = 0; i < num_spin; i++) {
            data[n + i] = data[i];
        }
        
        int cnt = 0;
        for (int i = 0; i <= num_spin; i++) {
            for (int j = i; j < n + i; j += num_spin + 1) {
                int sum = 0;
                for (int k = 0; k < num_spin + 1; k++) {
                    sum += HextoDec(data[j + k], k, num_spin + 1);
                }
                output[cnt++] = sum;
            }
        }
        
        sort(output, output + cnt, comp);
        
        for (int i = 0; i < k; i++) {
            if (i > 0 && output[i - 1] == output[i]) k++;
        }
        printf("#%d %d\n", tc, output[k - 1]);

        memset(data, 0, sizeof(data));
        memset(output, 0, sizeof(output));
    }
    return 0;
}