#include <stdio.h>
const int MAX = 100000;
int data[MAX];

void merge(int l_start, int l_end, int r_start, int r_end) {
  int temp[MAX];
  int p, q;
  
  p = l_start;
  q = r_start;
  
  int temp_idx = 0;
  while (p <= l_end && q <= r_end) {
    if (data[p] <= data[q]) {
      temp[temp_idx++] = data[p++];
    } else {
      temp[temp_idx++] = data[q++];
    }
  }
  
  if (p > l_end) {
    for (int i = q; i <= r_end; i++) {
      temp[temp_idx++] = data[i];
    }
  } else {
    for (int i = p; i <= l_end; i++) {
      temp[temp_idx++] = data[i];
    }    
  }
  
  for (int i = l_start; i <= r_end; i++) {
    data[i] = temp[i - l_start];
  }
}

void mergeSort(int start, int end) {
  if (start >= end) {
    return;
  } else {
    int mid = start + (end - start) / 2;
    
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, mid + 1, end);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%d ", &data[i]);
  }
  
  mergeSort(0, n - 1);
  
  for (int i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  return 0;
}