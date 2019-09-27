#include <stdio.h>
#define MAX 100000

bool check(int arr[], int interval, int n, int k) {
  int sum = 0;

  int i;
  for (i = 0; i < interval; i++) 
    sum += arr[i];
  
  if (sum >= k)
    return true;
    
  for (i = 0; i < n - interval; i++) {
    sum = sum - arr[i] + arr[i + interval];
    
    if (sum >= k) 
      return true;
  }
  return false;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  int arr[MAX];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  if (check(arr, 1, n, k)) {
    printf("1");
    return 0;
  } 
  
  if (!check(arr, n, n, k)) {
    printf("-1");
    return 0;
  }
  
  int start = 0;
  int end = n - 1;
  
  while (start + 1 < end) {
    int mid = start + (end - start) / 2;
    if (check(arr, mid, n, k))
      end = mid;
    else
      start = mid;
  }
  
  printf("%d", end);
  return 0;
}