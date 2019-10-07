#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
vector<int> cost[MAX];
int n, m;

void Dijkstra(int dist[], int src) {
  bool visited[MAX] = {false};
  
  for (int i = 1; i <= n; i++) 
    dist[i] = INT_MAX;
  
  dist[src] = 0;
  
  for (int i = 1; i <= n; i++) {
    int min_dist = INT_MAX, min_idx = -1;
    for (int j = 1; j <= n; j++) {
      if (!visited[j] && min_dist > dist[j]) {
        min_dist = dist[j];
        min_idx = j;
      }
    }
    
    visited[min_idx] = true;
    
    for (int j = 0; j < graph[min_idx].size(); j++) {
      int next_node = graph[min_idx][j];
      int next_cost = cost[min_idx][j];
      
      if (dist[next_node] > dist[min_idx] + next_cost)
        dist[next_node] = dist[min_idx] + next_cost;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  
  int v, w, c;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &v, &w, &c);
    graph[v].push_back(w);
    graph[w].push_back(v);
    cost[v].push_back(c);
    cost[w].push_back(c);
  }
  
  int A, B;
  scanf("%d %d", &A, &B);

  int distA[MAX], distB[MAX];
  Dijkstra(distA, A);
  Dijkstra(distB, B);
  
  
  int AB = distA[1] + distA[B] + distB[n];
  int BA = distB[1] + distB[A] + distA[n];
  
  if (AB > BA)
    printf("%d", BA);
  else
    printf("%d", AB);
  
  return 0;
}