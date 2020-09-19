#include <stdio.h>

const int MAX = 100005;

typedef struct _Queue {
  int data[MAX];
  int capacity = MAX;
  int numElem = 0;
  int f = 0, r = 0;
  
  void create(int y) {
    capacity = 0;
    numElem = 0;
    f = 0, r = 0;
  }
  
  void push(int elem) {
    if (numElem < capacity) {
      data[r] = elem;
      r = (r + 1) % MAX;
      numElem++;
    }
  }
  
  void pop() {
    if (numElem > 0) {
      data[f] = 0;
      f = (f + 1) % MAX;
      numElem--;
    }
  }
  
  int front() {
    if (numElem > 0) {
      return data[f];
    }
  }
  
  int size() {
    return numElem;
  }
  
  bool empty() {
    if (numElem <= 0)
      return true;
    else
      return false;
  }
}Queue;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  Queue q;
  q.push(k);

  int infected = 1;
  int visited[MAX];
  visited[k] = 1;
  
  while(!q.empty()) {
    int size = q.size();
    
    while (size--) {
      int current = q.front();
      q.pop();

      if (current > 0 && current <= n) {
        if (current * 2 <= n) {
          if (visited[current * 2] == 0) {
            visited[current * 2] = 1;
            q.push(current * 2);
            infected++;
          }
        }
        if (current / 3 > 0) {
          if (visited[current / 3] == 0) {
            visited[current / 3] = 1;
            q.push(current / 3);
            infected++;
          }
        }
      }
    }
  }

  printf("%d", n - infected);
  return 0;
}