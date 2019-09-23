#include <stdio.h>
#include <string.h>

int main() {
  char str[1001];
  scanf("%s", str);
  
  int idx = 0, cnt = 0;
  while (idx < strlen(str)) {
    int i = 0;
    while (1) {
      if (str[idx] == str[idx + i]) {
        cnt++;
        i++;
      } else {
        if (cnt > 1)
          printf("%d%c", cnt, str[idx]);
        else
          printf("%c", str[idx]);
        cnt = 0;
        idx += i;
        break;
      }
    }
  }
  return 0;
}