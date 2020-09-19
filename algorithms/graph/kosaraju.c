#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 100;

vector<int> graph[MAX];
vector<int> reversed_graph[MAX];
bool visited[MAX];
int sequence[MAX];
int n, m, cnt;

void GetSequence(int node) {
  visited[node] = true;
  
  for (int i = 0; i < graph[node].size(); i++) {
    int next_node = graph[node][i];
    if (!visited[next_node])
      GetSequence(next_node);
  }
  sequence[++cnt] = node;
}

void GetGroup(int node) {
  visited[node] = true;
  for (int i = 0; i < reversed_graph[node].size(); i++) {
    int next_node = reversed_graph[node][i];
    if (!visited[next_node])
      GetGroup(next_node);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  
  int v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    graph[v].push_back(w);
    reversed_graph[w].push_back(v);
  }
  
  for (int i = 1; i <= n; i++) {
    if (!visited[i])
      GetSequence(i);
  }
  
  memset(visited, false, sizeof(visited));
  
  int group_cnt = 0;
  for (int i = cnt; i >= 1; i--) {
    int node = sequence[i];
    if (!visited[node]) {
      GetGroup(node);
      group_cnt++;
    }
  }
  
  printf("%d", group_cnt);
  return 0;
}