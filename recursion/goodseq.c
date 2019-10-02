#include <stdio.h>

const int MAX = 100;
int data[MAX];
int n, flag = 0;

bool checkseq(int length) {
  int sum;
  for (int i = 1; i <= (length + 1) / 2; i++) {
    sum = 0;
    for (int j = 0; j < i; j++) {
      if (data[length - j] == data[length - i - j])
        sum++;
    }
    if (sum == i)
      return false;
  }
  return true;
}

void goodseq(int x) {
  if (x >= n) {
    for (int i = 0; i < n; i++) 
      printf("%d", data[i]);

    flag = 1;
  } else {
    for (int i = 1; i <= 3; i++) {
      if (i == 0) {
        data[x] = i;
        goodseq(x + 1);
      } else {
        if (data[x - 1] != i) {
          data[x] = i;
          if (checkseq(x))
            goodseq(x + 1);
        }
      }
      if (flag == 1)
        return;
    }
  }
}

int main() {
  scanf("%d", &n);
  
  goodseq(0);

  return 0;
}