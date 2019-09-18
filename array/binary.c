#include <stdio.h>

void toBinary(int x) {
  if (x == 0 || x == 1) {
    printf("%d", x);
  } else {
    toBinary(x/2);
    printf("%d", x%2);
  }
}

int main() {  
  int n;
  scanf("%d", &n);
  toBinary(n);

  return 0;
}   