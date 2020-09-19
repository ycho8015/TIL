#include <stdio.h>
int board[13];
int n, count;

bool isPromising(int y) {
  if (y < 1)
    return true;
  
  for (int i = 0; i < y; i++) {
    if (board[y] == board[i]) return false;
    
    int rise = y - i;
    int run = board[y] - board[i];
    run = run > 0 ? run : (-1) * run;
    
    if (rise == run) return false;
  }
  return true;
}

void DFS(int y) {
  if (y >= n) {
    count++;
  } else {
    for (int i = 0; i < n; i++) {
      board[y] = i;
      if (isPromising(y))
        DFS(y + 1);
    }
  }
}

int main() {
  scanf("%d", &n);
  
  DFS(0);
  printf("%d", count);
  
  return 0;
}