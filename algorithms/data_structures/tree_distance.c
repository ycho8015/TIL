#include <cstdio>
#include <vector>

using namespace std;
const int MAX = 1001;
int visited[MAX];
int length;

void FindDistance(vector <int> tree[], int current, int target, int dist) {
  visited[current] = 1;
  if (current == target) {
    length = dist;
    return;
  }
  for (int i = 0; i < tree[current].size(); i++) {
    int next = tree[current][i];
    if (visited[next] == 0) {
      FindDistance(tree, next, target, dist + 1);
    }
  }
}

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  
  vector <int> tree[MAX];
  
  int a, b;
  while (scanf("%d %d", &a, &b) == 2) {
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  FindDistance(tree, x, y, 0);
  printf("%d", length);
  
  return 0;
}