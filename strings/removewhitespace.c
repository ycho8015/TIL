#include <stdio.h>
#include <string.h>

const int MAX = 100000;

int main() {
  char str[MAX];
  char newStr[MAX];
  
  fgets(str, sizeof(str), stdin);
  
  int idx = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ' ') {
      newStr[idx++] = str[i];
    }
  }
  
  for (int i = 0; i < strlen(newStr); i++) {
    printf("%c", newStr[i]);
  }
  
  return 0;
}