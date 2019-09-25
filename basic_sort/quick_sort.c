#include <stdio.h>
const int MAX = 100000;

int getLeft(int start, int end, int pivot, int data[], int result[]) {
  int idx = 0;
  
  for (int i = start; i <= end; i++) {
    if (data[i] <= pivot) 
      result[idx++] = data[i];
  }
  return idx;
}

int getRight(int start, int end, int pivot, int data[], int result[]) {
  int idx = 0;
  
  for (int i = start; i <= end; i++) {
    if (data[i] > pivot)  
      result[idx++] = data[i];
  }
  return idx;
}

void quickSort(int data[], int start, int end) {
  if (start >= end) 
    return;
    
  int left[MAX], right[MAX];
  int pivot = data[start];
  
  int left_cnt = getLeft(start + 1, end, pivot, data, left);
  int right_cnt = getRight(start + 1, end, pivot, data, right);
  
  for (int i = 0; i < left_cnt; i++) {
    data[i + start] = left[i];
  }
  
  data[start + left_cnt] = pivot;
  
  for (int i = 0; i < right_cnt; i++) {
    data[i + start + left_cnt + 1] = right[i];
  }
  
  quickSort(data, start, start + left_cnt - 1);
  quickSort(data, start + left_cnt + 1, end);
}

int main() {
  int n;
  scanf("%d", &n);
  
  int data[MAX];
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  quickSort(data, 0, n - 1);
  
  for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  
  return 0;
}