#include <stdio.h>
#include <string.h>

int main() {
  
  int n;
  scanf("%d", &n);
  
  char str[101][101];
  
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
  }
  
  for (int i = 0; i < n; i++) {
    int idx = i;
    for (int j = i; j < n; j++) {
      if (strcmp(str[idx], str[j]) > 0) {
        idx = j;
      }
    }
    char temp[101];
    strcpy(temp, str[i]);
    strcpy(str[i], str[idx]);
    strcpy(str[idx], temp);
  }
  
  for (int i = 0; i < n; i++) {
    printf("%s\n", str[i]);
  }
  return 0;
}