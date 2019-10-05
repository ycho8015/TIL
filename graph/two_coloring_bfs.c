#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10000;

vector<int> graph[MAX];

bool visited[MAX][2];
int n, m;


bool BFS(int v) {
  queue<int> q;
  q.push(v);
  
  visited[v][0] = true;
  visited[v][1] = true;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int v = q.front();
      bool color = visited[v][1];
      q.pop();
      
      for (int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];
        if (!visited[w][0]) {
          visited[w][0] = true;
          visited[w][1] = !color;
          q.push(w);
        } else if (visited[w][0] && visited[w][1] == color) {
          return false;
        }
      }
    }
  }
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  
  int v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &v, &w);
    graph[v].push_back(w);
    graph[w].push_back(v);
  }
  
  bool flag = BFS(0);
  
  if (flag == true)
    printf("YES");
  else
    printf("NO");

  return 0;
}