#include <stdio.h>
char guesses[1000][6];
char num[4];
int check[10];
int n, cnt = 0;

void possibleAns(int x) {
  if (x >= 3) {
    int valid = 0;
    for (int i = 0; i < n; i++) {
      int strike = 0, ball = 0;
      for (int j = 0; j < 3; j++) {
        if (num[j] == guesses[i][j]) 
          strike++;
          
        for (int k = 0; k < 3; k++) {
          if (num[j] == guesses[i][k] && j != k)
            ball++;
        }
      }
      
      if (strike == guesses[i][3] - '0' && ball == guesses[i][4] - '0') {
        valid++;
      } else {
        return;
      }
    }
    
    if (valid == n) {
      cnt++;
    }
  } else {
    for (int i = 1; i <= 9; i++) {
      if (check[i] == 0) {
        check[i] = 1;
        num[x] = i + '0';
        possibleAns(x + 1);
        check[i] = 0;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf(" %c ", &guesses[i][j]);
    }
  }
  
  possibleAns(0);
  printf("%d", cnt);
  
  return 0;
}