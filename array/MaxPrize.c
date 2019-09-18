#include <stdio.h>

int main() {

  int n;
  scanf("%d", &n);
  int arr[3];
  int max_prize = 0;
  for (int i = 0; i < n; i++) {
    int max_num = 0, max_cnt = 0;
    for (int j = 0; j < 3; j++) {
      scanf("%d ", &arr[j]);
      if (arr[j] > max_num) {
        max_num = arr[j];
      }
    }
    
    int cnt = 0, num = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = j; k < 3; k++) {
        if (arr[j] == arr[k]) {
          cnt++;
        }
      }
      
      if (max_cnt < cnt) {
        max_cnt = cnt;
        num = arr[j];
      }
      cnt = 0;
    }
    int prize = 0;
    if (max_cnt == 1) {
      prize = max_num * 100;
    } else if (max_cnt == 2) {
      prize = 1000 + num * 100;
    } else {
      prize = 10000 + num * 1000;
    }
    
    if (prize > max_prize)
      max_prize = prize;
  }
  
  printf("%d", max_prize);
  return 0;
}