#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 100000;

int visited[MAX];
int n;

int BFS() {
  queue <pair<int, int>> q;
  
  q.push ( {1, 0} );
  visited[1] = 1;
  
  while (!q.empty()) {
    int size = (int)q.size();
    while (size--) {
      int current = q.front().first;
      int current_buttons = q.front().second;
      q.pop();
      
      if (current == n)
        return current_buttons;
      
      if (current * 2 <= 99999 && current > 0) {
        if (visited[current * 2] == 0) {
          visited[current * 2] = 1;
          q.push( {current * 2, current_buttons + 1} );
        }
      }
      
      if (current / 3 > 0 && current <= 99999) {
        if (visited[current / 3] == 0) {
          visited[current / 3] = 1;
          q.push( {current / 3, current_buttons + 1} );
        }
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  
  int num_buttons = BFS();
  printf("%d", num_buttons);
  
  return 0;
}