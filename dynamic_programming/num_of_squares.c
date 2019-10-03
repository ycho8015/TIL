#include <stdio.h>
const int MAX = 100001;
int main() {
  int n;
  scanf("%d", &n);
  
  int data[MAX] = {0};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (data[i] > data[i - j * j] + 1 || data[i] == 0)
        data[i] = data[i - j * j] + 1;
    }
  }
  
  printf("%d", data[n]);
  return 0;
}