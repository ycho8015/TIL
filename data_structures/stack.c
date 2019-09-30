#include <stdio.h>

struct Stack {
  int data[150];
  int capacity;
  int len;
  
  void create(int y) {
    capacity = y;
    len = 0;
  }
  
  void push(int element) {
    if (len < capacity) {
      data[len++] = element;
    } else {
        printf("Overflow\n");
    }
  }
  
  void pop() {
    if (len > 0) {
      data[len - 1] = 0;
      len--;
    } else {
        printf("Underflow\n");
    }
  }
  
  void top() {
    if (len > 0) {
      printf("%d\n", data[len - 1]);
    } else {
        printf("NULL\n");
    }
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  struct Stack s;
  s.create(n);
  
  int op, val;
  for (int i = 0; i < m; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &val);
      s.push(val);
    } else if (op == 2) {
        s.pop();
    } else {
        s.top();
    }
  }
  
  return 0;
}