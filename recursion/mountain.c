#include <stdio.h>

// depth first inorder tree traversal
void getMountain(int n) {
    if (n == 1) {
        printf("1");
    } else {
        getMountain(n - 1);
        printf("%d", n);
        getMountain(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    getMountain(n);

    return 0;
}