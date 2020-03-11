#include <stdio.h>
const int MAX = 100000;
int data[MAX];

int GCD(int a, int b) {
    if (a % b) return GCD(b, a % b);
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int gcd = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        if (i) gcd = GCD(gcd, data[i] - data[i - 1]);
    }
    
    printf("%d", (data[n - 1] - data[0]) / gcd + 1 - n);
    return 0;
}
