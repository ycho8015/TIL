#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 100;
vector<int> directed_lighter[MAX];
vector<int> directed_heavier[MAX];

int visited[MAX];
int n, m;
int lighter, heavier;

void lighterDFS(int bead) {
  if (lighter >= (n + 1) / 2)
    return;
    
  visited[bead] = 1;
  for (int i = 0; i < directed_lighter[bead].size(); i++) {
    int next_bead = directed_lighter[bead][i];
    if (!visited[next_bead]) {
      lighter++;
      lighterDFS(next_bead);
    }
  }
}

void heavierDFS(int bead) {
  if (heavier >= (n + 1) / 2)
    return;
    
  visited[bead] = 1;
  for (int i = 0; i < directed_heavier[bead].size(); i++) {
    int next_bead = directed_heavier[bead][i];
    if (!visited[next_bead]) {
      heavier++;
      heavierDFS(next_bead);
    }
  }  
}

int main() {
  scanf("%d %d", &n, &m);
  
  int a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    directed_lighter[a].push_back(b);
    directed_heavier[b].push_back(a);
  }
  
  int outliers_cnt = 0;
  for (int i = 1; i <= n; i++) {
    lighterDFS(i);
    memset(visited, 0, sizeof(visited));
    
    heavierDFS(i);
    memset(visited, 0, sizeof(visited));
    
    if (heavier >= (n + 1) / 2 || lighter >= (n + 1) / 2)
      outliers_cnt++;
    
    lighter = 0, heavier = 0;
  }  
  
  printf("%d", outliers_cnt);
  return 0;
}