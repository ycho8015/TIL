#include <stdio.h>
const int MAX = 1005;

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    
    int data[MAX][MAX];
    int i, j, area;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &area);
        if (j == 0)
          data[i][j] = area;
        else
          data[i][j] += data[i][j - 1] + area;
      }
    }
    
    int a, b, c, d, sum;
    for (i = 0; i < q; i++) {
      scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int j = a; j <= c; j++) {
          if (b > 0)
            sum += data[j][d] - data[j][b - 1];
          else
            sum += data[j][d];
        }
      printf("%d\n", sum);
      sum = 0;
    }
    
    return 0;
}