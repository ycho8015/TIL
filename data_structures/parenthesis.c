#include <stdio.h>
#include <string.h>

struct Stack {
  char data[51];
  int capacity;
  int len;
  
  void create(int y) {
    capacity = y;
    len = 0;
  }
  
  void push(char element) {
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
  
  char top() {
    if (len > 0) {
      return data[len - 1];
    } else {
      return NULL;
    }
  }
  
  bool empty() {
    if (len == 0) 
      return true;
    else
      return false;
  }
};

int main() {
  char str[51];
  scanf("%s", str);
  
  int size = strlen(str);
  if (size % 2 != 0) {
    printf("NO\n");
    return 0;
  }
  
  struct Stack s;
  s.create(51);
  
  for (int i = 0; i < size; i++) {
    if (str[i] == '(')
      s.push(str[i]);
    else {
      if (s.empty()) {
        printf("NO\n");
        return 0;
      }
      s.pop();
    }
  }
  
  if (s.empty()) 
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}