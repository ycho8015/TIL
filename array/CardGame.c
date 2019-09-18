#include <stdio.h>

int main() {
  int arr[2][10];
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 10; j++) {
      scanf("%d ", &arr[i][j]);
    }
  }
  
  int sumA = 0, sumB = 0;
  for (int i = 0; i < 10; i++) {
    if (arr[0][i] > arr[1][i]) {
      sumA++;
    } else if (arr[0][i] < arr[1][i]) {
      sumB++;
    }
  }
  
  if (sumA > sumB) {
    printf("A");
  } else if (sumA < sumB) {
    printf("B");
  } else {
    printf("D");
  }
  
  return 0;
}