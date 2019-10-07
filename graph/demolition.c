#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
int sequence[MAX];
bool visited[MAX];
int n, m, cnt;

void SCC(int node, int which) {
  visited[node] = true;
  
  for (int i = 0; i < graph[node].size(); i++) {
    int next_node = graph[node][i];
    if (!visited[next_node]) {
      SCC(next_node, which);
    }
  }
  if (which == 0) 
    sequence[++cnt] = node;
}

int main() {
  scanf("%d %d", &n, &m);
  
  int v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    graph[v].push_back(w);
  }
  
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      SCC(i, 0);
    }
  }
  
  memset(visited, false, sizeof(visited));
  
  int min_explosives = 0;
  for (int i = cnt; i >= 1; i--) {
    int node = sequence[i];
    if (!visited[node]) {
      SCC(node, 1);
      min_explosives++;
    }
  }
  
  printf("%d", min_explosives);
  return 0;
}