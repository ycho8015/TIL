#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1001;

vector<int> graph[MAX];
bool visited[MAX];
int n, m;

void ConnectedComp(int node) {
  visited[node]= true;
  
  for (int i = 0; i < graph[node].size(); i++) {
    int next_node = graph[node][i];
    if (!visited[next_node])
      ConnectedComp(next_node);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  int v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    graph[v].push_back(w);
    graph[w].push_back(v);
  }
  
  int num_connected_comp = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ConnectedComp(i);
      num_connected_comp++;
    }
  }
  
  printf("%d", num_connected_comp);
  return 0;
}