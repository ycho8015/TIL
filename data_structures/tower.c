#include <stdio.h>
#include <stack>

using namespace std;

struct stackNode {
  int height;
  int index;
};

int main() {
  int n;
  scanf("%d", &n);
  
  stack <stackNode> s;
  int height;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &height);
    
    if (i == 1) {
      printf("0 ");
      s.push( {height, i} );
    } else {
      if (height > s.top().height) {
        while (!s.empty()) {
          if (height > s.top().height) 
            s.pop();
          else
            break;
        }
        if (s.empty()) 
          printf("0 ");
        else 
          printf("%d ", s.top().index);
        
        s.push( {height, i} );
      } else {
        printf("%d ", s.top().index);
        s.push( {height, i} );
      }
    }
    
  }
  return 0;
}