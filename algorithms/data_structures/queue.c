#include <stdio.h>

struct Queue {
  int data[100];
  int capacity;
  int f, r;
  
  void create(int y) {
    capacity = y;
    f = 0;
    r = 0;
  }
  
  void push(int element) {
    if (r - f >= capacity || r >= capacity) 
      printf("Overflow\n");
    else
      data[r++] = element;
  }
  
  void pop() {
    if (r - f <= 0) 
      printf("Underflow\n");
    else
      data[f++] = 0;
  }
  
  void front() {
    if (r - f <= 0)
      printf("NULL\n");
    else
      printf("%d\n", data[f]);
  }
  
  int size() {
    return r - f;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  struct Queue q;
  q.create(n);
  
  int op, val;
  for (int i = 0; i < m; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &val);
      q.push(val);
    } else if (op == 2) {
      q.pop();
    } else {
      q.front();
    }
  }
  return 0;
}