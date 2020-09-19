#include <stdio.h>
#include <string.h>

void reverse(char * str, int length) {
  for (int i = 0; i < length / 2; i++) {
    char temp;
    temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }  
}

int main() {
  char A[102];
  char B[102];
  
  scanf("%s %s", A, B);
  
  // set length of A always greater than equal to B
  if (strlen(B) > strlen(A)) {
    char temp[102];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
  }  
  
  int lenA = strlen(A);
  int lenB = strlen(B);
  
  reverse(A, lenA);
  reverse(B, lenB);
  
  // compute sum of A and B
  int carry = 0;
  for (int i = 0; i < lenB; i++) {
    if (A[i] + B[i] - '0' + carry > '9') {
      A[i] = A[i] + B[i] - '0' - 10 + carry;
      carry = 1;
    } else {
      A[i] += B[i] - '0' + carry;
      carry = 0;
    }
  }
  
  // compute remaining digits of larger number
  for (int i = lenB; i < lenA; i++) {
    if (A[i] + carry > '9') {
      A[i] = '0';
      carry = 1;
    } else {
      A[i] += carry;
      carry = 0;
    }
  }
  
  // if carry exists
  if (carry) {
    A[lenA] = '1';
  }
  
  reverse(A, strlen(A));
  printf("%s", A);
  
  return 0;
}