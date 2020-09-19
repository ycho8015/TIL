#include <stdio.h>

int main() {

  int a, b;
  char op;
  scanf("%d", &a);
  scanf(" %c", &op);
  scanf("%d", &b);
  
  int result;
  if (op == '+') {
    result = a + b;
  } else if (op == '-') {
    result = a - b;
  } else if (op == '/') {
    result = a / b;
  } else {
    result = a * b;
  }
  
  printf("%d", result);
  return 0;
}