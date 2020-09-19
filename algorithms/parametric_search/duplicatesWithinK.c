#include <stdio.h>
#include <string.h>
#define MAX 100005

bool checkInterval(int arr[], int n, int interval) {
  int check[MAX] = {0};
  
  int duplicate = 0;
  for (int i = 0; i < interval; i++) {
    check[arr[i]] += 1;
    if (check[arr[i]] == 2) {
      duplicate++;
    }
  }
  
  if (duplicate == 0)
    return true;
    
  for (int i = 0; i < n - interval; i++) {
    check[arr[i]] -= 1;
    if (check[arr[i]] == 1) 
      duplicate--;
      
    check[arr[i + interval]] += 1;

    if (check[arr[i + interval]] == 2)
      duplicate++;
    
    if (duplicate == 0)
      return true;
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  
  int arr[MAX];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  int start = 1;
  int end = n + 1;
  
  while (start + 1 < end) {
    int mid = start + (end - start) / 2;
    if (checkInterval(arr, n, mid)) {
      start = mid;
    } else {
        end = mid;
    }
  }
  
  printf("%d", start);
  return 0;
}