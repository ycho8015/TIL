#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAX = 100;
char data[MAX];
int parenthesis[MAX];

int n, max_sum = INT_MIN;

int calculate(int a, int op, int b) {
  if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else
    return a * b;
}

void solve (int y) {
  if (y >= n - 1) {
    vector<int> v;
    int i = 0;
    while (i < n) {
      if (!parenthesis[i]) {
        if (data[i] >= '0' && data[i] <= '9')
          v.push_back(data[i] - '0');
        else
          v.push_back(data[i]);
        i++;
      } else {
        v.push_back(calculate(data[i] - '0', data[i + 1], data[i + 2] - '0'));
        i+=3;
      }
    }

    int result = v[0];
    for (int i = 1; i < v.size(); i += 2) {
      if (v[i] == '+') {
        result += v[i + 1];
      } else if (v[i] == '-') {
        result -= v[i + 1];
      } else
        result *= v[i + 1];  
    }
    if (result > max_sum)
      max_sum = result;
  } else {
    for (int i = y; i < n; i += 2) {
      if (parenthesis[i] == 0 && parenthesis[i + 2] == 0 && i + 2 < n) {
        parenthesis[i] = 1;
        parenthesis[i + 2] = 1;
        solve(y + 2);
        parenthesis[i] = 0;
        parenthesis[i + 2] = 0;
      }
    }
   solve(y + 2);
  }
}
int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf(" %c", &data[i]);
  }

  solve(0);
  printf("%d\n", max_sum);

  return 0;
}