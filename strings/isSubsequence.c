#include <stdio.h>
#include <string.h>

int main() {
  char A[1000], B[1000];
  
  scanf("%s %s", A, B);
  
  if (strlen(A) < strlen(B)) {
    char temp[1000];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
  }
  
  for (int i = 0; i < strlen(A); i++) {
    int flag = 0;
    if (strlen(A) - i >= strlen(B)) {
      for (int j = 0; j < strlen(B); j++) {
        if (A[i + j] != B[j]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        printf("YES");
        return 0;
      }
    }
  }
  
  printf("NO");
  return 0;
}