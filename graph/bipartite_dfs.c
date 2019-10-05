#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1000;
vector <int> graph[MAX];
bool visited[MAX][2];
int n, m, flag;

void isBipartite(int v, int color) {
  visited[v][0] = true;
  visited[v][1] = color;
  
  for (int i = 0; i < graph[v].size(); i++) {
    int w = graph[v][i];
    if (!visited[w][0])
      isBipartite(w, !color);
    if (flag == 1)
      return;
    if (visited[w][1] == color) {
      flag = 1;
      return;
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  
  int v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    graph[v].push_back(w);
    graph[w].push_back(v);
  }
  
  isBipartite(1, 0);
  if (flag == 0)
    printf("Yes");
  else
    printf("No");
    
  return 0;
}