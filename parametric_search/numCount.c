#include <stdio.h>
#define MAX 100000

int n, q;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) 
      swap(&arr[++i], &arr[j]);
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

int countValue(int arr[], int mid, int value) {
  int idx = 1;
  int count = 1;
  
  while (true) {
    if (arr[mid + idx] == value && mid + idx < n) {
      count++;
      idx++;
    } else {
      break;
    }
  }
  
  idx = -1;
  while (true) {
    if (arr[mid + idx] == value && mid + idx >= 0) {
      count++;
      idx--;
    } else {
      break;
    }
  }
  return count;
}
int binarySearch(int arr[], int low, int high, int value) {
  if (low > high) 
    return 0;
  
  int mid = low + (high - low) / 2;
  
  if (arr[mid] == value)
    return countValue(arr, mid, value);
  else if (arr[mid] > value)
    return binarySearch(arr, low, mid - 1, value);
  else
    return binarySearch(arr, mid + 1, high, value);
}

void quickSort(int arr[], int low, int high) {
  if (low >= high)
    return;
  
  int pi = partition(arr, low, high);
  
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
}

int main() {
  scanf("%d %d", &n, &q);
  
  int arr[MAX];
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  
  quickSort(arr, 0, n - 1);

  int num;
  for (i = 0; i < q; i++) {
    scanf("%d", &num);
    printf("%d\n", binarySearch(arr, 0, n - 1, num));
  }

  return 0;
}