#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100000

int trees[MAX];

int main() {
  int n;
  scanf("%d", &n);
  
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    scanf("%d", &trees[i]);
    if (i > 0) {
      if (trees[i] - trees[i - 1] < min) 
        min = trees[i] - trees[i - 1];
    }
  }
  
  int num_trees = 0;
  while (true) {
    int flag = 0;
    for (int i = 1; i < n; i++) {
      if ((trees[i] - trees[i - 1]) % min != 0) {
        flag = 1;
        min--;
        break;
      }
    }
    
    if (flag == 0) {
      for (int i = 1; i < n; i++) {
        num_trees += (trees[i] - trees[i - 1]) / min - 1;
      }
      break;
    }
  }
  
  printf("%d", num_trees);
  return 0;
}