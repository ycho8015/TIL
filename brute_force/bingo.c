#include <stdio.h>
#include <stdbool.h>

int board[5][5];

bool isBingo() {
  int i, j, flag = 0, cnt = 0;
  
  // check rows
  for (i = 0; i < 5; i++) {
    flag = 0;
    for (j = 0; j < 5; j++) {
      if (board[i][j] != 0) {
        flag = 1;
        break;
      } 
    }
    if (flag == 0) {
      cnt++;
      if (cnt >= 3)
        return true;
    }
  }
  
  // check cols 
  for (j = 0; j < 5; j++) {
    int flag = 0;
    for (i = 0; i < 5; i++) {
      if (board[i][j] != 0) {
        flag = 1;
        break;
      } 
    }
    if (flag == 0) {
      cnt++;
      if (cnt >= 3)
        return true;
    }
  }  
  
  // left diag
  flag = 0;
  for (i = 0; i < 5; i++) {
    if (board[i][i] != 0) {
      flag = 1;
      break;
    }
  }
  
  if (flag == 0) {
    cnt++;
    if (cnt >= 3)
      return true;
  }
  
  // right diag
  i = 0, flag = 0;
  for (j = 4; j >= 0; j--) {
    if (board[i++][j] != 0) {
      flag = 1;
      break;
    }
  }
  
  if (flag == 0) {
    cnt++;
    if(cnt >= 3) 
      return true;
  }
  return false;
}

bool solve(int x) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == x) {
        board[i][j] = 0;
        break;
      }
    }
  }
  
  if (isBingo()) 
    return true;
    
  return false;
}

int main() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d ", &board[i][j]);
    }
  }
  
  int num;
  for (int i = 1; i <= 25; i++) {
    scanf("%d ", &num);
    if(solve(num)) {
      printf("%d", i);
      return 0;
    }
  }
  
  return 0;
}