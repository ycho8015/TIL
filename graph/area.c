#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 101;

int map[MAX][MAX];
int visited[MAX][MAX];
int direction[2][4]
={
  {-1, 1, 0, 0},
  {0, 0, 1, -1}
};
int n, m, k;

void Swap(int* a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int data[], int low, int high) {
  int pivot = data[high];
  int i = low;
  
  for (int j = low; j < high; j++) {
    if (data[j] < pivot) {
      Swap(&data[i], &data[j]);
      i++;
    }
  }
  Swap(&data[i], &data[high]);
  return i;
}

void QuickSort(int data[], int low, int high) {
  if (low >= high)
    return;
    
  int pi = Partition(data, low, high);
  
  QuickSort(data, low, pi - 1);
  QuickSort(data, pi + 1, high);
}

bool isValid(int y, int x) {
  if (y >= 0 && x >= 0 && y < n && x < m)
    if (!visited[y][x] && !map[y][x]) 
      return true;
  return false;
}

int BFS(int y, int x) {
  int count = 1;
  queue<pair<int,int>> q;
  q.push( {y, x} );
  visited[y][x] = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      
      for (int i = 0; i < 4; i++) {
        int ny = y + direction[0][i];
        int nx = x + direction[1][i];
        
        if (isValid(ny, nx)) {
          visited[ny][nx] = 1;
          q.push( {ny, nx} );
          count++;
        }
      }
    }
  }
  return count;
}

int main() {
  scanf("%d %d %d", &m, &n, &k);
  
  int y1, x1, y2, x2;
  for (int i = 0; i < k; i++) {
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i >= y1 && i < y2 && j >= x1 && j < x2)
          map[i][j] = 1;
      }
    }
  }
  
  int area[MAX] = {0};
  int num_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0 && !visited[i][j]) {
        int output = BFS(i, j);
        area[num_area++] = output;
      }
    }
  }
  
  QuickSort(area, 0, num_area - 1);
  
  printf("%d\n", num_area);
  for (int i = 0; i < num_area; i++) {
    printf("%d ", area[i]);
  }
  
  return 0;
}