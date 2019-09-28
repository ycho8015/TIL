#include <stdio.h>
#include <limits.h>

long long int checkCount(long long int data[][2], long long int mid, int n) {
  long long int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (data[i][0] > mid)
      continue;
    else if (data[i][1] < mid)
      cnt += data[i][1] - data[i][0] + 1;
    else
      cnt += mid - data[i][0];
  }
  return cnt;
}

int main() {
  int n;
  scanf("%d", &n);
  
  long long int data[10000][2];
  long long int start = LONG_MAX, end = 0;
  
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &data[i][0], &data[i][1]);
    if (start > data[i][0])
      start = data[i][0];
    if (end < data[i][1])
      end = data[i][1];
  }
  
  end += 1;
  
  long long int k;
  scanf("%lld", &k);
  
  while (start + 1 < end) {
    int mid = start + (end - start) / 2;
    
    if (checkCount(data, mid, n) <= k)
      start = mid;
    else
      end = mid;
  }
  
  printf("%d", start);
  return 0;
}