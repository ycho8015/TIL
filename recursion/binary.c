#include <stdio.h>

void printBinary(int n) {
    if (n == 0) {
        printf("0");
    } else if (n == 1) {
        printf("1");
    } else {
        printBinary(n / 2);
        printf("%d", n % 2);    
    }
}

int main() {
  int n;
  scanf("%d", &n);
  
  printBinary(n);

  return 0;
}