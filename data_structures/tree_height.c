#include <cstdio>
#include <vector>

using namespace std;
const int MAX = 100;
int visited[MAX];
int height = 0;

void FindHeight(vector<int> tree[], int node, int depth) {
  visited[node] = 1;
  if (depth > height) 
    height = depth;
  for (int i = 0; i < tree[node].size(); i++) {
    int next_node = tree[node][i];
    if (visited[next_node] == 0) {
      FindHeight(tree, next_node, depth + 1);
    }
  }
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  
  vector <int> tree[MAX];
  int a, b;
  while (scanf("%d %d", &a, &b) == 2) {
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  FindHeight(tree, r, 0);
  printf("%d", height);  
  return 0;
}