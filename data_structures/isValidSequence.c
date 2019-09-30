#include <stdio.h>
#include <string.h>

struct Stack {
  char data[27];
  int capacity;
  int len;
  
  void create(int y) {
    capacity = y;
    len = 0;
  }
  
  void push(char element) {
    if (len < capacity) {
      data[len++] = element;
      printf("push\n");
    } else {
        printf("Overflow\n");
    }
  }
  
  void pop() {
    if (len > 0) {
      data[len - 1] = 0;
      len--;
      printf("pop\n");
    } else {
        printf("Underflow\n");
    }
  }
  
  char top() {
    if (len > 0) {
      return data[len - 1];
    } else {
        return NULL;
    }
  }
};

int main() {
  char str[27];
  scanf("%s", str);
  
  int size = strlen(str);
  int i;
  for (i = 1; i < size; i++) {
    if (str[i - 1] > str[i] + 1) {
      printf("impossible\n");
      return 0;
    }
  }
  
  struct Stack s;
  s.create(27);
  
  int idx = 0;
  char alphabet = 'a';
  for (i = 0; i < size; i++) {
    while (true) {
      if (s.top() < str[idx]) {
        s.push(alphabet++);
      } else {
          break;
      }
    }
    s.pop();
    idx++;
  }
  return 0;
}