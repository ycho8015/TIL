#include <stdio.h>
#include <string.h>
const int MAX = 1001;
int data[MAX][MAX];
char str[MAX];

int min(int a, int b) {
  return a < b ? a : b; 
}

int main() {
  scanf("%s", str);

  int length = strlen(str);
  for (int i = length - 1; i >= 0; i--) {
    for (int j = i; j < length; j++) {
      if (i != j) {
        if (str[i] == str[j])
          data[i][j] = data[i + 1][j - 1];
        else {
          data[i][j] = min(data[i + 1][j], data[i][j - 1]) + 1;          
        }
      }
    }
  }
  
  printf("%d ", data[0][length - 1]);
  
  return 0;
}