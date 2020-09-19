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
  char A[102]={0};
  char B[102]={0};
  scanf("%s %s", A, B);
  
  if (strlen(A) < strlen(B)) {
    char temp[102];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
  }
  reverse(A, strlen(A));
  reverse(B, strlen(B));
  
  int row = strlen(B) + 1;
  int col = strlen(A) + strlen(B);
  char result[101][201]={0};
  int carry;
  for (int i = 0; i < strlen(B); i++)  {
    carry = 0;
    for (int k = 0; k < i; k++) {
      result[i][k] = '0';
    }
    for (int j = 0; j < strlen(A); j++) {
      int val = (A[j] - '0') * (B[i] - '0') + carry;
      if (val > 9) {
        result[i][j + i] = val % 10 + '0';
        carry = val / 10;
      } else {
        result[i][j + i] = val + '0';
        carry = 0;
      }
    }
    if (carry > 0) 
      result[i][strlen(A) + i] = carry + '0';
  }
  
  carry = 0;
  for (int j = 0; j < col; j++) {
    int sum = carry;
    for (int i = 0; i < row - 1; i++) {
      if (result[i][j] != 0)
        sum += result[i][j] - '0';
    }
    if (sum > 9) {
      result[row - 1][j] = sum % 10 + '0';
      carry = sum / 10;
    } else {
      result[row - 1][j] = sum + '0';
      carry = 0;
    }
  }
  
  for (int j = col - 1; j > 0; j--) {
    if (result[row - 1][j] == '0') {
      result[row - 1][j] = 0;  
    } else {
      break;
    }
  }
  reverse(result[row - 1], strlen(result[row - 1]));
  printf("%s", result[row - 1]);

  return 0;
}