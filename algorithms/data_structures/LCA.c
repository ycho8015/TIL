#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int MAX = 1000;
int visited[MAX];
int length, flag = 0;

void LCA(vector <int> tree[], int path[], int parent, int depth, int target) {
  if (parent == target) {
    length = depth;
    flag = 1;
    return;
  } else {
    if (parent == 0) {
      path[0] = parent;
      visited[parent] = 1;
    }
    
    for (int i = 0; i < tree[parent].size(); i++) {
      int next_node = tree[parent][i];
      if (visited[next_node] == 0) {
        visited[next_node] = 1;
        path[depth] = next_node;
        LCA(tree, path, next_node, depth + 1, target);
        if (flag == 1)
          return;
      }
    }
  }
}

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  
  vector <int> tree[MAX];
  
  int a, b;
  while(scanf("%d %d", &a, &b) == 2) {
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  int path_x[MAX], path_y[MAX];
  
  int len_x, len_y;
  LCA(tree, path_x, 0, 1, x);
  len_x = length;
  flag = 0;
  memset(visited, 0, sizeof(visited));
  LCA(tree, path_y, 0, 1, y);
  len_y = length;
  
  length = len_x > len_y ? len_y : len_x;

  for (int i = length - 1; i >= 0; i--) {
    if (path_x[i] == path_y[i]) {
      printf("%d", path_x[i]);
      return 0;
    }
  }
  return 0;
}