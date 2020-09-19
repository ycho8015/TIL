#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 100001;

int visited[MAX];
int n, k;

int BFS() {
  queue<int> q;
  q.push(k);
  visited[k] = 1;
  int infected = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int current = q.front();
      q.pop();
      
      if (current * 2 > 0 && current * 2 <= n) {
        if (visited[current * 2] == 0) {
          visited[current * 2] = 1;
          q.push(current * 2);
          infected++;
        }
      }
      
      if (current / 3 > 0 && current <= n) {
        if (visited[current / 3] == 0) {
          visited[current / 3] = 1;
          q.push(current / 3);
          infected++;
        }
      }
    }
  }
  return infected;
}

int main() {
  scanf("%d %d", &n, &k);
  
  int infected = BFS();
  
  printf("%d", n - infected);
  return 0;
}