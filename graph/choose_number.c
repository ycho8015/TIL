#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 101;

vector<int> graph[MAX];
int visited[MAX];
int path[MAX];
int n, path_cnt;

void checkCycle(int src, int dest) {
  visited[src] = 1;
  
  if (src == dest && !path[dest]) {
    path[dest] = 1;
    path_cnt++;
  }
  
  for (int i = 0; i < graph[src].size(); i++) {
    int next_node = graph[src][i];
    if (!visited[next_node]) {
      checkCycle(next_node, dest);
    }
  }
}

int main() {
  scanf("%d", &n);
  
  for (int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    graph[i].push_back(num);
  }
  
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      checkCycle(graph[i][0], i);
      memset(visited, 0, sizeof(visited));
    }
  }
  
  printf("%d\n", path_cnt);
  for (int i = 1; i <= n; i++) {
    if (path[i])
      printf("%d ", i);
  }
  return 0;
}