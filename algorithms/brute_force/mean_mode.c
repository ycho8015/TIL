#include <stdio.h>

int main() {
  int arr[1001] = {0};
  int mean = 0, max = 0;
  for (int i = 0; i < 10; i++) {
    int num;
    scanf("%d", &num);
    arr[num] += 1;
    if (num > max) {
      max = num;
    }
    mean += num;
  }
  
  int mode = 0, mode_idx = 0;
  for (int i = 10; i <= max; i += 10) {
    if (arr[i] > mode) {
      mode = arr[i];
      mode_idx = i;
    }
  }
  printf("%d\n%d", mean/10, mode_idx);
  return 0;
}