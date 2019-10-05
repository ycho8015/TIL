#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 10000;
vector <int> graph[MAX];
bool visited[MAX][2];
int n, m, flag = 0;

void TwoColoring(int v, int color) {
  visited[v][0] = true;
  visited[v][1] = color;
  
  for (int i = 0; i < graph[v].size(); i++) {
    int w = graph[v][i];
    if (visited[w][0] == false)  
      TwoColoring(w, !color);
      
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
  
  TwoColoring(0, 0);
  if (flag == 0)
    printf("YES");
  else
    printf("NO");
  return 0;
}