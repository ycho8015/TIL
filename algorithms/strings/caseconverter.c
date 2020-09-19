#include <stdio.h>
#include <string.h>
const int MAX = 1001;

int main() {
  char str[MAX];
  fgets(str, sizeof(str), stdin);
  
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] -= 'a' - 'A';
    else if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += 'a' - 'A';
  }
  
  for (int i = 0; i < strlen(str); i++) {
    printf("%c", str[i]);
  }
  return 0;
}