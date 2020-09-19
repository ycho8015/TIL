#include <stdio.h>
const int MAX = 100;

typedef struct _Queue {
  int data[MAX];
  int capacity;
  int numElement;
  int f, r;
  
  void create(int y) {
    capacity = y;
    numElement = 0;
    f = 0, r = 0;
  }
  
  void push(int element) {
    if (numElement >= capacity) {
      printf("Overflow\n");
    } else {
      data[r] = element;
      r = (r + 1) % MAX;
      numElement++;
    }
  }
  
  void pop() {
    if (numElement <= 0) {
      printf("Underflow\n");
    } else {
      data[f] = 0;
      f = (f + 1) % MAX;
      numElement--;
    }
  }
  
  void front() {
    if (numElement <= 0) {
      printf("NULL\n");
    } else {
      printf("%d\n", data[f]);
    }
  }
  
  int size() {
    return numElement;
  }
}Queue;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  Queue q;
  q.create(n);
  
  int op, elem;
  for (int i = 0; i < m; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &elem);
      q.push(elem);
    } else if (op == 2) {
      q.pop();
    } else {
      q.front();
    }
  }
  return 0;
}