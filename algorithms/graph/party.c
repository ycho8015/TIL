#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;
const int MAX = 1001;

int n, m, k;

int dijkstra(vector<int>* graph, vector<int>* cost, int src) {
  bool visited[MAX] = {false};
  int dist[MAX];
  
  for (int i = 1; i <= n; i++) 
    dist[i] = INT_MAX;
  
  dist[src] = 0;
  for (int i = 1; i <= n; i++) {
    int min_dist = INT_MAX, min_idx = 0;
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
      
      if (dist[next_node] > dist[min_idx] + next_cost) {
        dist[next_node] = dist[min_idx] + next_cost;
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) 
    sum += dist[i];
  return sum;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  
  vector<int> graph[MAX];
  vector<int> cost[MAX];
  vector<int> reversed_graph[MAX];
  vector<int> reversed_cost[MAX];
  
  int v, w, c;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &v, &w, &c);
    graph[v].push_back(w);
    cost[v].push_back(c);
    reversed_graph[w].push_back(v);
    reversed_cost[w].push_back(c);
  }
  
  int total_dist = dijkstra(graph, cost, k);
  int total_reversed_dist = dijkstra(reversed_graph, reversed_cost, k);
  
  printf("%d", total_dist + total_reversed_dist);
  
  return 0;
}