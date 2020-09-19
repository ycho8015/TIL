#include <stdio.h>
#include <string.h>

int main() {
  char str[1001];
  fgets(str, sizeof(str), stdin);
  
  for (int i = 0; i < strlen(str) / 2; i++) {
    char temp;
    temp = str[i];
    str[i] = str[strlen(str) - i - 1];
    str[strlen(str) - i - 1] = temp;
  }

  for (int i = 0; i < strlen(str); i++) {
    printf("%c", str[i]);
  }
  return 0;
}