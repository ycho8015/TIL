#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int a, b, n;
int data[100000]={0};
int min_val;

int binarySearch(int current, int start, int end) {
  if (start >= end) {
    if (abs(current + data[start - 1]) > abs(current + data[end])) {
        if (min_val > abs(current + data[end])) {
          min_val = abs(current + data[end]);
          a = current;
          b = data[end];
        }
    } else {
        if (min_val > abs(current + data[end])) {
          min_val = abs(current + data[start - 1]);
          a = current;
          b = data[start - 1];
        }
    }
  } else {
      int mid = start + (end - start) / 2;
      if (min_val > abs(current + data[mid])) {
        min_val = abs(current + data[mid]);
        a = current;
        b = data[mid];
      }
      if (current + data[mid] == 0) {
        return data[mid];
      } else if (current + data[mid] > 0) {
          binarySearch(current, start, mid - 1);
      } else {
          binarySearch(current, mid + 1, end);
      }
  }
}
int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i ++) 
    scanf("%d", &data[i]);
  
  sort(data, data + n);
  
  if (data[0] > 0) {
    printf("%d %d", data[0], data[1]);
    return 0;
  } else if (data[n - 1] < 0) {
      printf("%d %d", data[n - 2], data[n - 1]);
      return 0;
  }
  
  for (int i = 0; i < n - 1; i++) {
    if (i == 0) {
      a = data[i];
      b = data[i+1];
      min_val = abs(a + b);
    }
    int val = binarySearch(data[i], i+1, n-1);
    if(data[i] + val == 0) {
      printf("%d %d", data[i], val);
      return 0;
    }
  }
  printf("%d %d", a, b);
  return 0;
}