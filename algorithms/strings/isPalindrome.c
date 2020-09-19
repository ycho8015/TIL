#include <stdio.h>
#include <string.h>

int main() {
  char str[1001];
  scanf("%s", str);
  
  for (int i = 0; i < strlen(str) / 2; i++) {
    if(str[i] != str[strlen(str) - i - 1]) {
      printf("NO");
      return 0;
    }
  }
  
  printf("YES");
  return 0;
}