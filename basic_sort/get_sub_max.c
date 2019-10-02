#include <stdio.h>
#include <limits.h>
const int MAX = 100000;

int GetSubMax(int data[], int start, int end) {
  if (start >= end)
    return data[start];
  
  int mid = start + (end - start) / 2;
  
  int left = GetSubMax(data, start, mid);
  int right = GetSubMax(data, mid + 1, end);
  
  int left_max = INT_MIN, left_sum = 0;
  int i;
  for (i = mid; i >= start; i--) {
    left_sum += data[i];
    if (left_max < left_sum)
      left_max = left_sum;
  }
  
  int right_max = INT_MIN, right_sum = 0;
  for (i = mid + 1; i <= end; i++)  {
    right_sum += data[i];
    if (right_max < right_sum)
      right_max = right_sum;
  }
  
  int max = left_max + right_max;
    
  if (left > right && left > max) return left;
  else if (right > left && right > max) return right;
  else return max;
}
int main() {
  int n;
  scanf("%d", &n);
  int data[MAX];

  for (int i = 0; i < n; i++) 
    scanf("%d", &data[i]);
    
  printf("%d", GetSubMax(data, 0, n - 1));
  
  return 0;
}