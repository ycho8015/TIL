#include <stdio.h>
#define MAX 300000

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      swap(&arr[++i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low >= high) 
    return;
  
  int pi = partition(arr, low, high);
  
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
}

void merge(int arr[], int s1, int e1, int s2, int e2) {
  int temp[MAX];
  int p, q;
  
  p = s1;
  q = s2;
  
  int idx = 0;
  while (p <= e1 && q <= e2) {
    if (arr[p] <= arr[q]) 
      temp[idx++] = arr[p++];
    else
      temp[idx++] = arr[q++];
  }
  
  int i;
  if (p > e1) {
    for (i = s2; i <= e2; i++) {
      temp[idx++] = arr[q++];
    }
  } else {
      for (i = s1; i <= e1; i++) {
        temp[idx++] = arr[p++];
      }
  }
  
  for (i = s1; i <= e2; i++) {
    arr[i] = temp[i - s1];
  }
}

void mergeSort(int arr[], int low, int high) {
  if (low >= high) 
    return;
    
  int mid = low + (high - low) / 2;
  
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, mid + 1, high);
}

bool binarySearch(int arr[], int low, int high, int value) {
  if (low <= high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == value) 
      return true;
    else if (arr[mid] > value) 
      return binarySearch(arr, low, mid - 1, value);
    else
      return binarySearch(arr, mid + 1, high, value);
  }
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  
  int arr[MAX];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  quickSort(arr, 0, n - 1);
  //mergeSort(arr, 0, n - 1);
  
  int m;
  scanf("%d", &m);
  
  int num;
  for (i = 0; i < m; i++) {
    scanf("%d", &num);
    printf("%d\n", binarySearch(arr, 0, n - 1, num));
  }
  
  return 0;
}