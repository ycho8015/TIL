#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 101;

vector<int> graph[MAX];

int visited[MAX];
int n, m, infected;

void BFS() {
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int v = q.front();
      q.pop();
      
      for (int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];
        if (!visited[w]) {
          visited[w] = 1;
          infected++;
          q.push(w);
        }
      }
    }
  }

}
int main() {
  scanf("%d\n%d", &n, &m);
  
  int v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    graph[v].push_back(w);
    graph[w].push_back(v);
  }
  
  BFS();
  
  printf("%d", infected);
  return 0;
}