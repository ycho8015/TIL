#include <stdio.h>
#include <string.h>

const int MAX = 1005;

int data[MAX][MAX];
char A[MAX], B[MAX];

int min (int a, int b) {
  return a < b ? a : b;
}

int main() {
  scanf("%s %s", A, B);

  int len_A = strlen(A);
  int len_B = strlen(B);

  int i;
  for (i = 0; i <= len_A; i++) 
    data[i][0] = i;
  
    
  int j;
  for (j = 0; j <= len_B; j++) 
    data[0][j] = j;
  
  
  for (i = 1; i <= len_A; i++) {
    for (j = 1; j <= len_B; j++) {
      if (A[i - 1] == B[j - 1])
        data[i][j] = data[i - 1][j - 1];
      else
        data[i][j] = min(data[i - 1][j], data[i][j - 1]) + 1;
    }
  }
  
  // for (i = 0; i <= len_A; i++) {
  //   for (j = 0; j <= len_B; j++) {
  //     printf("%d ", data[i][j]);
  //   }
  //   printf("\n");
  // }
  
  printf("%d", data[len_A][len_B]);
  return 0;
}