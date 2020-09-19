#include <stdio.h>

int main() {

  int map[10][10];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      scanf("%d ", &map[i][j]);
    }
  }
  
  int cnt = 0;
  while (cnt < n) {
    for(int i = 0; i < 10; i++) {
      map[cnt][i] = map[cnt][i] == 0 ? 1 : 0;
      if (cnt != i)
        map[i][cnt] = map[i][cnt] == 0 ? 1 : 0;
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