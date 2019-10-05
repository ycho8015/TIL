#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 101;
vector <int> graph[MAX];
bool visited[MAX];
int n, m, cnt;

void checkVirus(int v) {
  visited[v] = true;
  
  for (int i = 0; i < graph[v].size(); i++) {
    int w = graph[v][i];
    if (!visited[w]) {
      cnt++;
      checkVirus(w);
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
  
  checkVirus(1);
  printf("%d", cnt);
  return 0;
}