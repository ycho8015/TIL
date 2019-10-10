#include <stdio.h>
const int MAX = 1001;

struct Tree {
  int root;
  int left;
  int right;
};

Tree tree[MAX];
int map[MAX][MAX];
int row = 1, col;

void inOrder(int x, int count) {
  if (tree[x].left == -1 && tree[x].right == -1) {
    if (count > row)
      row = count;
    map[count][col++] = x;
  } else {
    int left = tree[x].left;
    int right = tree[x].right;
    
    if (left != - 1)
      inOrder(left, count + 1);
    
    map[count][col++] = x;
    
    if (right != -1)
      inOrder(right, count + 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    int root, left, right;
    scanf("%d %d %d", &root, &left, &right);
    tree[root].left = left;
    tree[root].right = right;
  }
  
  inOrder(1, 1);

  int max_width_row = 0, max_width = 0;
  for (int i = 1; i <= row; i++) {
    int left_col_idx = 1001, right_col_idx = 0, width = 0;
    for (int j = 0; j < col; j++) {
      if (map[i][j] && left_col_idx > j) {
        left_col_idx = j;        
      }
      if (map[i][j] && right_col_idx < j) {
        right_col_idx = j;
      }
    }
    width = right_col_idx - left_col_idx + 1;
    if (width > max_width) {
      max_width = width;
      max_width_row = i;
    }
  }
  
  printf("%d %d", max_width_row, max_width);
  return 0;

}