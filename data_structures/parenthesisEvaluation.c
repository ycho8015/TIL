#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

const int kMAX = 35;
char data[kMAX];

int main() {
  scanf("%s", &data);
  
  stack <char> s;
  if (data[0] == ']' || data[0] == ')' || strlen(data) % 2 != 0) {
    printf("0");
    return 0;
  }
  
  int temp = 1;
  int result = 0;
  for (int i = 0; i < strlen(data); i++) {
    if (data[i] == '(' || data[i] == '[') {
      if (data[i] == '(') {
        temp *= 2;
      } else { 
        temp *= 3;
      }
      s.push(data[i]);
    } else {
      if (s.top() == '(') {
        if (data[i] == ']') {
          printf("0");
          return 0;
        } else {
          if (data[i-1] == '(') {
            result += temp;
          }
          s.pop();
          temp /= 2;
        }
      } else if(s.top() == '[') {
        if (data[i] == ')') {
          printf("0");
          return 0;
        } else {
          if (data[i-1] == '[') {
            result += temp;
          }
          s.pop();
          temp /= 3;
        }
      } 
    }
  }
  if (!s.empty()) {
    printf("0");
  }
  else { 
    printf("%d", result);
  }
  
  return 0;
}