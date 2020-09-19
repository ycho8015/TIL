#include <stdio.h>

int main() {
  int n;
  scanf("%d ", &n);
  int map[10][10]={0};
  
  int cnt = 0;
  while (cnt < n) {
    for (int i = 0; i < 10; i++) {
      if (map[cnt][i] == 0) {
        map[cnt][i] = 1;
      } else {
        map[cnt][i] = 0;
      }
      
      if (i != cnt) {
        if (map[i][cnt] == 0) {
          map[i][cnt] = 1;
        } else {
          map[i][cnt] = 0;
        }
      }
    }
    
    cnt++;
  }
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}