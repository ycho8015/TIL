#include <stdio.h>

typedef struct _Tree {
  int root;
  int left;
  int right;
}Tree;

void TreeTraversal(Tree tree[], int parent, int order) {
  if (tree[parent].left == -1 && tree[parent].right == -1) {
    printf("%d ", parent);
  } else {
    if (order == 0) {
      printf("%d ", parent);
      if (tree[parent].left != -1) 
        TreeTraversal(tree, tree[parent].left, order);
      if (tree[parent].right != -1)
        TreeTraversal(tree, tree[parent].right, order);
    } else if (order == 1) {
      if (tree[parent].left != -1) 
        TreeTraversal(tree, tree[parent].left, order);
      printf("%d ", parent);
      if (tree[parent].right != -1)
        TreeTraversal(tree, tree[parent].right, order);      
    } else {
      if (tree[parent].left != -1) 
        TreeTraversal(tree, tree[parent].left, order);
      if (tree[parent].right != -1)
        TreeTraversal(tree, tree[parent].right, order);  
      printf("%d ", parent);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  Tree tree[n];
  for (int i = 0; i < n; i++) 
    scanf("%d %d %d", &tree[i].root, &tree[i].left, &tree[i].right);
  
  for (int i = 0; i < 3; i++) {
    TreeTraversal(tree, 0, i);
    printf("\n");
  }
  
  return 0;
}