#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct qNode {
  int num;
  int dist;
};

const int MAX = 10000;
vector<int> graph;

bool check(int a, int b) {
  int cnt = 0;
  
  while (a > 0) {
    if (a % 10 == b % 10)
      cnt++;
    a /= 10;
    b /= 10;
  }
  if (cnt == 3)
    return true;
  return false;
}

int BFS(int src, int dest) {
  int visited[MAX] = {0};
  visited[src] = 1;
  queue<qNode> q;
  q.push( {src, 0} );
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int num = q.front().num;
      int dist = q.front().dist;
      q.pop();
      
      for (int i = 0; i < graph.size(); i++) {
        int next_num = graph[i];
        if (check(num, next_num) && !visited[next_num]) {
          if (next_num == dest) 
            return dist + 1;
          visited[next_num] = 1;
          q.push( {next_num, dist + 1} );
        }
      }
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  
  int primes[MAX] = {0};
  for (int i = 2; i < MAX; i++) {
    for (int j = 2; j < MAX; j++) {
      if (i * j >= MAX) 
        break;
      primes[i * j] = 1;
    }
  }
  
  for (int i = 2; i < MAX; i++) {
    if (!primes[i])
      graph.push_back(i);
  }
  
  for (int tc = 1; tc <= T; tc++) {
    int src, dest;
    scanf("%d %d", &src, &dest);
    if (src == dest) {
      printf("0\n");
      continue;
    } 
    
    int num_edit = BFS(src, dest);
    if (num_edit > 0)
      printf("%d\n", num_edit);
    else
      printf("impossible\n");
  }
  
  return 0;
}