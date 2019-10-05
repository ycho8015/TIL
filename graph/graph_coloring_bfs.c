#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 25;

int map[MAX][MAX];
int visited[MAX][MAX];
int dydx[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int result[50];

int n;

void Swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

bool isValid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < n) 
    if (map[y][x] == '1' && !visited[y][x]) 
      return true;
  return false;
}

int BFS(int y, int x) {
  int group_cnt = 1;
  queue <pair<int, int>> q;
  q.push( {y, x} );
  visited[y][x] = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
        int ny = y + dydx[0][i];
        int nx = x + dydx[1][i];
        
        if (isValid(ny, nx)) {
          visited[ny][nx] = 1;
          group_cnt++;
          q.push( {ny, nx} );
        }
      }
    }
  }
  return group_cnt;
}

int Partition(int result[], int low, int high) {
  int pivot = result[high];
  int i = low;
  
  for (int j = low; j < high; j++) {
    if (result[j] < pivot) {
      Swap(&result[i], &result[j]);
      i++;
    }
  }
  Swap(&result[i], &result[high]);
  return i;
}

void QuickSort(int reuslt[], int low, int high) {
  if (low >= high)
    return;
  
  int pi = Partition(result, low, high);
  
  QuickSort(result, low, pi - 1);
  QuickSort(result, pi + 1, high);
}

void Merge(int result[], int s1, int e1, int s2, int e2) {
  int temp[50];
  
  int p = s1, q = s2, idx = 0;
  while (p <= e1 && q <= e2) {
    if (result[p] <= result[q]) 
      temp[idx++] = result[p++];
    else 
      temp[idx++] = result[q++];
  }
  
  int i;
  if (p > e1) {
    for (i = q; i <= e2; i++) 
      temp[idx++] = result[i];
  } else {
    for (i = p; i <= e1; i++) 
      temp[idx++] = result[i];
  }
  
  for (i = s1; i <= e2; i++) 
    result[i] = temp[i - s1];
}

void MergeSort(int result[], int low, int high) {
  if (low >= high)
    return;
  
  int mid = low + (high - low) / 2;
  
  MergeSort(result, low, mid);
  MergeSort(result, mid + 1, high);
  Merge(result, low, mid, mid + 1, high);
}

int main() {
  scanf("%d", &n);
  
  int i, j;
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++)
      scanf(" %c", &map[i][j]);
      
  int group = 0, cnt = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (isValid(i, j)) {
        cnt = BFS(i, j);
        result[group] = cnt;
        group++;
      }
    }
  }
  
  printf("%d\n", group);
  
  MergeSort(result, 0, group - 1);
  //QuickSort(result, 0, group - 1);
  
  for (i = 0; i < group; i++) {
    printf("%d\n", result[i]);
  }
  
  return 0;
}