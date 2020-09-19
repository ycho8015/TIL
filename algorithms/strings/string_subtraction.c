#include <stdio.h>
#include <string.h>

void reverse(char str[], int length) {
  for (int i = 0; i < length / 2; i++) {
    char temp;
    temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }  
}

int main() {
  char A[105]={0};
  char B[105]={0};
  
  scanf("%s", A);
  scanf("%s", B);
  
  int sign = 0;
  if (strlen(B) > strlen(A)) {
    char temp[102];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
    sign = 1;
  } else if (strlen(A) == strlen(B)) {
    if (strcmp(A, B) < 0) {
      char temp[102];
      strcpy(temp, A);
      strcpy(A, B);
      strcpy(B, temp);
      sign = 1;
    }
  }
  
  reverse(A, strlen(A));
  reverse(B, strlen(B));
  
  int carry = 0;
  for (int i = 0; i < strlen(B); i++) {
    if (A[i] - carry < B[i]) {
      A[i] = A[i] + 10 - carry - B[i] + '0';
      carry = 1;
    } else {
      A[i] = A[i] - B[i] - carry + '0';
      carry = 0;
    }
  }
  
  for (int i = strlen(B); i < strlen(A); i++) {
    if (carry == 1) {
      if (A[i] == '0') {
        A[i] = '9';
        carry = 1;
      } else {
        A[i] -= carry;
        carry = 0;
      }
    } else {
      break;
    }
  }
  

  for (int i = strlen(A) - 1; i > 0; i--) {
    if (A[i] == '0') {
      A[i] = 0;
    } else {
      break;
    }
  }
  
  if (sign) {
    A[strlen(A)] = '-';
  }
  
  reverse(A, strlen(A));
  printf("%s", A);
  return 0;
}