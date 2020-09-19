#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];
vector<int> reversed_graph[MAX];

int visited[MAX];
int order[MAX];
int order_time;
int cnt;

void getOrder(int node) {
  visited[node] = 1;
  
  for (int i = 0; i < graph[node].size(); i++) {
    int next_node = graph[node][i];
    if (!visited[next_node])
      getOrder(next_node);
  }
  order[++order_time] = node;
}

void getGroup(int src, int dest) {
  visited[src] = 1;
  
  for (int i = 0; i < reversed_graph[src].size(); i++) {
    int next_node = reversed_graph[src][i];
    
    if (next_node == dest) {
      cnt++;
      return;
    }
    
    if (!visited[next_node]) {
      cnt++;
      getGroup(next_node, dest);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  int node;
  for (int i = 1; i <= n; i++) {  
    scanf("%d", &node);
    graph[i].push_back(node);
    reversed_graph[node].push_back(i);
  }
  
  for (int i = 1; i <= n; i++) {
    if (!visited[i])
      getOrder(i);  
  }
  
  memset(visited, 0, sizeof(visited));
  
  int in_group = n;
  for (int i = order_time; i >= 1; i--) {
    int node = order[i];
    if (!visited[node]) {
      getGroup(node, node);
      in_group -= cnt;
      cnt = 0;
    }
  }
  
  printf("%d", in_group);
  return 0;
}