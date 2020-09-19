#include <stdio.h>
#define MAX 1000000

bool check(int arr[], int mid, int n, int m) {
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > mid)
      sum += arr[i] - mid;
    if (sum >= m) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  int arr[MAX];
  
  for (int i = 0; i < n; i++) 
    scanf("%d", &arr[i]);
  
  int start = 0;
  int end = 1000000000;
  while (start + 1 < end) {
    int mid = start + (end - start) / 2;
    if (check(arr, mid, n, m)) {
      start = mid;  
    } else {
        end = mid;
    }
  }
  printf("%d", start);
  return 0;
}